#define CATCH_CONFIG_MAIN

#include <atomic>
#include <string>
#include <tuple>
#include <vector>
#include <barkeep/barkeep.h>
#include <catch2/catch.hpp>

#include "testutil.h"

using namespace std::chrono_literals;
using namespace barkeep;

void check_anim(const std::vector<std::string>& parts,
                const std::string& msg,
                const std::vector<std::string>& stills) {
  auto incr = [&](size_t idx) {
    std::string still = stills[idx];
    while (still == stills[idx]) { idx = (idx + 1) % stills.size(); }
    return idx;
  };

  size_t j = 0;
  for (size_t i = 0; i < parts.size() - 1; i++) {
    auto& part = parts[i];
    if (part != (msg + " " + stills[j] + " ")) { j = incr(j); }
    CHECK(part == (msg + " " + stills[j] + " "));
  }
}

void check_status(const std::vector<std::string>& parts,
                  const std::vector<std::string>& messages,
                  const std::vector<std::string>& stills) {
  auto incr = [&](size_t idx) {
    std::string still = stills[idx];
    while (still == stills[idx]) { idx = (idx + 1) % stills.size(); }
    return idx;
  };

  size_t still_i = 0;
  size_t msg_i = 0;

  for (size_t i = 0; i < parts.size() - 1; i++) {
    auto& part = parts[i];
    if (part != (messages[msg_i] + " " + stills[still_i] + " ")) {
      // either msg_i or stills_i (or both) need to be incremented
      if (part == (messages[msg_i] + " " + stills[incr(still_i)] + " ")) {
        still_i = incr(still_i);
      } else if (part == (messages[msg_i + 1] + " " + stills[still_i] + " ")) {
        msg_i++;
      } else {
        still_i = incr(still_i);
        msg_i++;
      }
    }
    CHECK(part == (messages[msg_i] + " " + stills[still_i] + " "));
  }
}

TEST_CASE("Animation default", "[anim]") {
  auto anim = Animation({.show = false});
  anim->done();
}

TEST_CASE("Animation", "[anim]") {
  std::stringstream out;

  auto sty = GENERATE(Ellipsis, Clock, Moon, Earth, Bar, Bounce);
  auto no_tty = GENERATE(true, false);
  auto interval = GENERATE(as<std::variant<Duration, double>>(), 100ms, 0.1);

  auto anim = Animation({
      .out = &out,
      .message = "Working",
      .style = sty,
      .interval = interval,
      .no_tty = no_tty,
  });

  std::this_thread::sleep_for(1s);
  anim->done();

  auto parts = check_and_get_parts(out.str(), no_tty);
  check_anim(parts, "Working", animation_stills_[size_t(sty)].first);
}

TEST_CASE("Animation custom", "[anim]") {
  std::stringstream out;

  auto sty = std::vector<std::string>{"a", "b", "c"};
  auto no_tty = GENERATE(true, false);
  auto interval = GENERATE(as<std::variant<Duration, double>>(), 100ms, 0.1);

  auto anim = Animation({
      .out = &out,
      .message = "Working",
      .style = sty,
      .interval = interval,
      .no_tty = no_tty,
  });

  std::this_thread::sleep_for(1s);
  anim->done();

  auto parts = check_and_get_parts(out.str(), no_tty);
  check_anim(parts, "Working", sty);
}

TEST_CASE("Status", "[status]") {
  std::stringstream out;

  auto sty = GENERATE(Ellipsis, Clock, Moon, Earth, Bar, Bounce);
  auto no_tty = GENERATE(true, false);
  auto interval = GENERATE(as<std::variant<Duration, double>>(), 100ms, 0.1);

  auto stat = Status({
      .out = &out,
      .message = "Working",
      .style = sty,
      .interval = interval,
      .no_tty = no_tty,
  });

  std::this_thread::sleep_for(0.5s);
  stat->message("Still working");
  std::this_thread::sleep_for(0.5s);
  stat->message("Done");
  stat->done();

  auto parts = check_and_get_parts(out.str(), no_tty);
  check_status(parts,
               {"Working", "Still working", "Done"},
               animation_stills_[size_t(sty)].first);
  CHECK(stat->message() == "Done");
}

using ProgressTypeList =
    std::tuple<size_t, std::atomic<size_t>, int, unsigned, float, double>;

TEMPLATE_LIST_TEST_CASE("Counter default", "[counter]", ProgressTypeList) {
  using ValueType = value_t<TestType>;
  TestType amount{GENERATE(as<ValueType>(), 0, 3)};

  auto ctr = Counter(&amount, {.show = false});
  ctr->done();
}

TEMPLATE_LIST_TEST_CASE("Counter constant", "[counter]", ProgressTypeList) {
  std::stringstream out;

  using ValueType = value_t<TestType>;

  TestType amount{GENERATE(as<ValueType>(), 0, 3)};
  auto sp = GENERATE(as<std::optional<double>>(), std::nullopt, 1);
  std::string unit = GENERATE("", "thing/10ms");

  auto ctr = Counter(&amount,
                     {
                         .out = &out,
                         .message = "Doing things",
                         .speed = sp,
                         .speed_unit = unit,
                         .interval = 0.001s,
                     });
  for (size_t i = 0; i < 101; i++) {
    std::this_thread::sleep_for(0.13ms);
    // no work
  }
  ctr->done();

  auto parts = check_and_get_parts(out.str());

  std::stringstream ss;
  if (std::is_floating_point_v<TestType>) {
    ss << std::fixed << std::setprecision(2);
  }
  ss << amount;
  std::string amountstr = ss.str();

  std::string expected = "Doing things " + amountstr + " ";
  if (sp == 1.) {
    if (unit.empty()) {
      expected += "(0.00) ";
    } else {
      expected += "(0.00 " + unit + ") ";
    }
  }

  for (auto& part : parts) { CHECK(part == expected); }
}

TEMPLATE_LIST_TEST_CASE("Counter", "[counter]", ProgressTypeList) {
  std::stringstream out;

  using ValueType = value_t<TestType>;

  TestType amount{GENERATE(as<ValueType>(), 0, 3)};
  ValueType initial = amount;
  auto sp = GENERATE(as<std::optional<double>>(), std::nullopt, 1);
  bool no_tty = GENERATE(true, false);
  std::string unit = GENERATE("", "thing/10ms");

  auto ctr = Counter(&amount,
                     {
                         .out = &out,
                         .message = "Doing things",
                         .speed = sp,
                         .speed_unit = unit,
                         .interval = 0.01s,
                         .no_tty = no_tty,
                     });
  ValueType increment = ValueType(1.2); // becomes 1 for integral types
  for (size_t i = 0; i < 101; i++) {
    std::this_thread::sleep_for(1.3ms);
    amount += increment;
  }
  ctr->done();

  auto parts = check_and_get_parts(out.str(), no_tty);
  auto counts = extract_counts<ValueType>("Doing things ", parts);

  for (size_t i = 1; i < counts.size(); i++) {
    CHECK(counts[i] >= counts[i - 1]);
  }

  // Final result should always be displayed
  ValueType expected = initial;
  if (std::is_floating_point_v<ValueType>) {
    expected += ValueType(121.2);
  } else {
    expected += ValueType(101);
  }
  CHECK(counts.back() == expected);
}

TEST_CASE("Decreasing counter", "[counter]") {
  std::stringstream out;
  int amount = 101;

  auto ctr = Counter(&amount,
                     {
                         .out = &out,
                         .message = "Doing things",
                         .interval = 0.01,
                     });
  for (size_t i = 0; i < 101; i++) {
    std::this_thread::sleep_for(1.3ms);
    amount--;
  }
  ctr->done();

  auto parts = check_and_get_parts(out.str());
  auto counts = extract_counts<int>("Doing things ", parts);

  for (size_t i = 1; i < counts.size(); i++) {
    CHECK(counts[i] <= counts[i - 1]);
  }

  // Final result should always be displayed
  CHECK(counts.back() == 0);
}

template <typename Display>
auto factory_helper(bool /*speedy*/ = false);

template <>
auto factory_helper<AnimationDisplay>(bool /*speedy*/) {
  static std::stringstream hide;
  return Animation({.out = &hide, .show = false});
}

template <>
auto factory_helper<StatusDisplay>(bool /*speedy*/) {
  static std::stringstream hide;
  return Status({.out = &hide, .show = false});
}

template <>
auto factory_helper<CounterDisplay<>>(bool speedy) {
  static size_t progress;
  static std::stringstream hide;
  if (speedy) {
    return Counter(&progress, {.out = &hide, .speed = 1, .show = false});
  } else {
    return Counter(&progress, {.out = &hide, .show = false});
  }
}

template <>
auto factory_helper<ProgressBarDisplay<float>>(bool speedy) {
  static float progress;
  static std::stringstream hide;
  if (speedy) {
    return ProgressBar(&progress, {.out = &hide, .speed = 1, .show = false});
  } else {
    return ProgressBar(&progress, {.out = &hide, .show = false});
  }
}

template <>
auto factory_helper<CompositeDisplay>(bool speedy) {
  static size_t progress;
  static std::stringstream hide;
  if (speedy) {
    return ProgressBar(&progress, {.out = &hide, .speed = 1, .show = false}) |
           Counter(&progress, {.out = &hide, .speed = 1, .show = false});
  } else {
    return ProgressBar(&progress, {.out = &hide, .show = false}) |
           Counter(&progress, {.out = &hide, .show = false});
  }
}

using DisplayTypes = std::tuple<AnimationDisplay,
                                StatusDisplay,
                                CounterDisplay<>,
                                ProgressBarDisplay<float>,
                                CompositeDisplay>;

TEMPLATE_LIST_TEST_CASE("Error cases", "[edges]", DisplayTypes) {
  auto orig = factory_helper<TestType>(GENERATE(true, false));
  orig->show();
  SECTION("Running compose 2") {
    CHECK_THROWS(orig | orig);
    CHECK_THROWS(orig | orig | orig);
  }
  // This is now a no-op, instead of error.
  CHECK_NOTHROW(orig->show());
  orig->done();
  CHECK_NOTHROW(orig->done());
}

TEST_CASE("Invalid speed discount", "[edges]") {
  double invalid = GENERATE(as<double>(), -1, 1.1);

  int progress = 0;
  CHECK_THROWS(Counter(&progress, {.speed = invalid}));
  CHECK_THROWS(ProgressBar(&progress, {.speed = invalid}));
}

TEMPLATE_LIST_TEST_CASE("Destroy before done", "[edges]", DisplayTypes) {
  CHECK_NOTHROW([]() {
    { // lifetime
      auto display = factory_helper<TestType>();
      display->show();
    }
  }());
}

// TEMPLATE_LIST_TEST_CASE("Copy & move", "[edges]", DisplayTypes) {
//   CHECK_NOTHROW([]() {
//     auto orig = factory_helper<TestType>(GENERATE(true, false));
//     auto copy = orig;
//     auto moved = std::move(orig);
//     copy.show();
//     copy.done();
//     moved.show();
//     moved.done();
//   }());
// }

void check_shrinking_space(const Strings& parts, const BarParts& sty) {
  // Check that space is shrinking
  size_t last_spaces = std::numeric_limits<size_t>::max();
  size_t first_spaces = std::numeric_limits<size_t>::max();
  for (auto& part : parts) {
    size_t spaces;
    if (sty.middle_modifier.empty() or sty.right_modifier.empty()) {
      spaces = size_t(std::count(part.begin(), part.end(), ' '));
    } else {
      size_t left = part.find(sty.middle_modifier);
      size_t right = part.find(sty.right_modifier, left);
      spaces = right - left - 1;
    }
    CHECK(spaces <= last_spaces);
    last_spaces = spaces;
    if (first_spaces == std::numeric_limits<size_t>::max()) {
      first_spaces = spaces;
    }
  }

  // Final spaces should be strictly smaller (not <=)
  CHECK(last_spaces < first_spaces);
}

void check_shrinking_space(const Strings& parts, ProgressBarStyle sty) {
  check_shrinking_space(parts, progress_bar_parts_[size_t(sty)]);
}

TEMPLATE_LIST_TEST_CASE("Progress bar", "[bar]", ProgressTypeList) {
  std::stringstream out;
  TestType progress{0};

  bool no_tty = GENERATE(true, false);
  auto sty = GENERATE(Bars, Blocks, Rich);

  auto bar = ProgressBar(&progress,
                         {
                             .out = &out,
                             .total = 50,
                             .message = "Computing",
                             .style = sty,
                             .interval = 0.001s,
                             .no_tty = no_tty,
                         });
  bar->show();
  for (size_t i = 0; i < 50; i++) {
    std::this_thread::sleep_for(1.3ms);
    progress++;
  }
  bar->done();

  auto parts = check_and_get_parts(out.str(), no_tty);

  // Check that message is correct
  for (auto& part : parts) { CHECK(part.substr(0, 10) == "Computing "); }

  // Check that default speed unit does not appear
  for (auto& part : parts) { CHECK(part.find("it/s") == std::string::npos); }

  // Check that space is shrinking
  check_shrinking_space(parts, sty);
}

TEMPLATE_LIST_TEST_CASE("Progress bar custom", "[bar]", ProgressTypeList) {
  std::stringstream out;
  TestType progress{0};

  bool no_tty = GENERATE(true, false);
  BarParts sty{"[", "]", {"|"}, {" "}};

  auto bar = ProgressBar(&progress,
                         {
                             .out = &out,
                             .total = 50,
                             .message = "Computing",
                             .style = sty,
                             .interval = 0.001s,
                             .no_tty = no_tty,
                         });
  bar->show();
  for (size_t i = 0; i < 50; i++) {
    std::this_thread::sleep_for(1.3ms);
    progress++;
  }
  bar->done();

  auto parts = check_and_get_parts(out.str(), no_tty);

  // Check that message is correct
  for (auto& part : parts) { CHECK(part.substr(0, 10) == "Computing "); }

  // Check that default speed unit does not appear
  for (auto& part : parts) { CHECK(part.find("it/s") == std::string::npos); }

  // Check that space is shrinking
  check_shrinking_space(parts, sty);
}

TEST_CASE("Iterable bar", "[bar]") {
  std::stringstream out;

  std::vector<int> things(50, 3);
  int dummy_sum = 0;

  auto no_tty = GENERATE(true, false);
  auto sty = GENERATE(Bars, Blocks, Rich);

  // TODO: is misalignment below a clang-format issue?
  for (auto& thing : IterableBar(things,
                                 {
                                     .out = &out,
                                    .message = "Computing",
                                    .style = sty,
                                    .interval = 0.001s,
                                    .no_tty = no_tty,
                                 })) {
    dummy_sum += thing;
    std::this_thread::sleep_for(1.3ms);
  }

  CHECK(dummy_sum == 150);

  auto parts = check_and_get_parts(out.str(), no_tty);

  // Check that message is correct
  for (auto& part : parts) { CHECK(part.substr(0, 10) == "Computing "); }

  // Check that default speed unit does not appear
  for (auto& part : parts) { CHECK(part.find("it/s") == std::string::npos); }

  // Check that space is shrinking
  check_shrinking_space(parts, sty);
}

TEMPLATE_LIST_TEST_CASE("Speedy progress bar", "[bar]", ProgressTypeList) {
  std::stringstream out;
  TestType progress{0};
  using ValueType = value_t<TestType>;

  bool no_tty = GENERATE(true, false);
  auto sty = GENERATE(Bars, Blocks, Rich);
  auto default_speed_unit = GENERATE(true, false);

  auto cfg = default_speed_unit ? ProgressBarConfig<ValueType>{
                                      .out = &out,
                                      .total = 50,
                                      .message = "Computing",
                                      .speed = 1,
                                      .style = sty,
                                      .interval = 0.001s,
                                      .no_tty = no_tty,
                                  }
                                  : ProgressBarConfig<ValueType>{
                                        .out = &out,
                                        .total = 50,
                                        .message = "Computing",
                                        .speed = 1,
                                        .speed_unit = "thing/time",
                                        .style = sty,
                                        .interval = 0.001s,
                                        .no_tty = no_tty,
                                    };

  auto bar = ProgressBar(&progress, cfg);

  bar->show();
  for (size_t i = 0; i < 50; i++) {
    std::this_thread::sleep_for(1.3ms);
    progress++;
  }
  bar->done();

  auto parts = check_and_get_parts(out.str(), no_tty);

  // Check that message is correct
  for (auto& part : parts) { CHECK(part.substr(0, 10) == "Computing "); }

  // Check speed unit
  if (default_speed_unit) {
    for (auto& part : parts) {
      CHECK(part.find("it/s") != std::string::npos);
      CHECK(part.find("thing/time") == std::string::npos);
    }
  } else {
    for (auto& part : parts) {
      CHECK(part.find("it/s") == std::string::npos);
      CHECK(part.find("thing/time") != std::string::npos);
    }
  }

  // Check that space is shrinking
  check_shrinking_space(parts, sty);
}

TEST_CASE("Speedy iterable bar", "[bar]") {
  std::stringstream out;

  std::vector<int> things(50, 3);
  int dummy_sum = 0;

  bool no_tty = GENERATE(true, false);
  auto default_speed_unit = GENERATE(true, false);

  auto sty = GENERATE(Bars, Blocks, Rich);

  if (default_speed_unit) {
    for (auto& thing : IterableBar(things,
                                   {
                                       .out = &out,
                                      .message = "Computing",
                                      .speed = 1,
                                      .style = sty,
                                      .interval = 0.001s,
                                      .no_tty = no_tty,
                                   })) {
      std::this_thread::sleep_for(1.3ms);
      dummy_sum += thing;
    }
  } else {
    for (auto& thing : IterableBar(things,
                                   {
                                       .out = &out,
                                      .message = "Computing",
                                      .speed = 1,
                                      .speed_unit = "thing/time",
                                      .style = sty,
                                      .interval = 0.001s,
                                      .no_tty = no_tty,
                                   })) {
      std::this_thread::sleep_for(1.3ms);
      dummy_sum += thing;
    }
  }

  CHECK(dummy_sum == 150);

  auto parts = check_and_get_parts(out.str(), no_tty);

  // Check that message is correct
  for (auto& part : parts) { CHECK(part.substr(0, 10) == "Computing "); }

  // Check speed unit
  if (default_speed_unit) {
    for (auto& part : parts) {
      CHECK(part.find("thing/time") == std::string::npos);
      CHECK(part.find("it/s") != std::string::npos);
    }
  } else {
    for (auto& part : parts) {
      CHECK(part.find("it/s") == std::string::npos);
      CHECK(part.find("thing/time") != std::string::npos);
    }
  }

  // Check that space is shrinking
  check_shrinking_space(parts, sty);
}

TEST_CASE("Progress bar out-of-bounds", "[bar][edges]") {
  std::stringstream out;
  int progress;

  auto bar = ProgressBar(&progress,
                         {
                             .out = &out,
                             .total = 50,
                             .message = "Computing",
                             .speed_unit = "",
                             .style = Bars,
                             .interval = 0.001s,
                             .show = false,
                         });

  SECTION("Above") {
    progress = 50;
    bar->show();
    for (size_t i = 0; i < 50; i++) {
      std::this_thread::sleep_for(1.3ms);
      progress++;
    }
    bar->done();

    auto parts = check_and_get_parts(out.str());
    for (auto part : parts) {
      CHECK(part.find(std::string(32, '|')) != std::string::npos);
    }
  }

  SECTION("Below") {
    progress = 0;
    bar->show();
    for (size_t i = 0; i < 50; i++) {
      std::this_thread::sleep_for(1.3ms);
      progress--;
    }
    bar->done();

    auto parts = check_and_get_parts(out.str());
    for (auto part : parts) {
      CHECK(part.find("|" + std::string(30, ' ') + "|") != std::string::npos);
    }
  }
}

// TEMPLATE_LIST_TEST_CASE("Zero total progress",
//                         "[bar][edges]",
//                         ProgressTypeList) {
//   TestType progress;
//   CHECK_THROWS(ProgressBar(&progress, {.total = 0}));
//   // TODO: make this not an error
// }

TEST_CASE("Composite bar-counter", "[composite]") {
  std::stringstream out;

  std::atomic<size_t> sents{0}, toks{0};
  auto bar = ProgressBar(&sents,
                         {
                             .out = &out,
                             .total = 505,
                             .message = "Sents",
                             .style = Bars,
                             .interval = 0.01,
                             .show = false,
                         }) |
             Counter(&toks,
                     {
                         .out = &out,
                         .message = "Toks",
                         .speed = 1,
                         .speed_unit = "tok/s",
                         .show = false,
                     });
  bar->show();
  for (int i = 0; i < 505; i++) {
    std::this_thread::sleep_for(0.13ms);
    sents++;
    toks += size_t(1 + rand() % 5);
  }
  bar->done();

  auto parts = check_and_get_parts(out.str());
  long last_spaces = std::numeric_limits<long>::max(), last_count = 0;

  for (auto& part : parts) {
    CHECK(part.substr(0, 6) == "Sents ");
    CHECK(part.substr(54, 6) == " Toks ");
    auto part_ = rstrip(part); // Right-hand side can have >=1 spaces
    CHECK(part_.substr(part_.size() - 7, 7) == " tok/s)");

    { // check bar correctness
      auto bar_part = part.substr(14, 32);
      long spaces = std::count(bar_part.begin(), bar_part.end(), ' ');
      CHECK(spaces <= last_spaces);
      last_spaces = spaces;
      size_t i = 1;
      while (bar_part[i] != ' ' and i < 31) { CHECK(bar_part[i++] == '|'); }
      while (i < 31) { CHECK(bar_part[i++] == ' '); }
    }

    { // check counter correctness
      auto count_part = part.substr(60, part.size());
      auto i = count_part.find_first_of(' ');
      long count = std::stol(count_part.substr(0, i));
      CHECK(count >= last_count);
      last_count = count;
    }
  }
}

TEST_CASE("Three bars multiline", "[composite]") {
  std::stringstream out;
  std::atomic<size_t> linear{0}, quad{0}, cubic{0};
  // clang-format off
  auto bars = Composite(
    {ProgressBar(&linear, {
          .out = &out,
          .total = 100,
          .message = "Linear   ",
          .speed = 0,
          .style = Rich,
          .show = false,
      }),
      ProgressBar(&quad, {
          .total = 5050,
          .message = "Quadratic",
          .speed = 0,
          .style = Rich,
          .show = false,
      }),
      ProgressBar(&cubic, {
          .total = 171700,
          .message = "Cubic    ",
          .speed = 0,
          .style = Rich,
          .show = false,
      })},
    "\n");
  // clang-format on
  bars->show();
  for (int i = 0; i < 100; i++) {
    std::this_thread::sleep_for(65ms);
    linear++;
    quad += linear;
    cubic += quad;
  }
  bars->done();
  auto parts = check_and_get_parts(out.str());
  std::vector<std::vector<std::string>> interleaved_parts(3);
  for (auto& part : parts) {
    auto lines = split(part, '\n');
    REQUIRE(lines.size() == 3);
    CHECK(startswith(lines[0], "Linear   "));
    CHECK(startswith(lines[1], "Quadratic"));
    CHECK(startswith(lines[2], "Cubic    "));
    interleaved_parts[0].push_back(lines[0]);
    interleaved_parts[1].push_back(lines[1]);
    interleaved_parts[2].push_back(lines[2]);
  }

  check_shrinking_space(interleaved_parts[0], Rich);
  check_shrinking_space(interleaved_parts[1], Rich);
  check_shrinking_space(interleaved_parts[2], Rich);
}