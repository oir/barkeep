#define CATCH_CONFIG_MAIN

#include <algorithm>
#include <atomic>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
#include <barkeep/barkeep.h>
#include <catch2/catch.hpp>

using namespace std::chrono_literals;
using namespace barkeep;

std::vector<std::string> split(const std::string& s, char delim) {
  std::vector<std::string> elems;
  std::stringstream ss(s);
  std::string elem;

  while (std::getline(ss, elem, delim)) { elems.push_back(elem); }

  return elems;
}

std::vector<std::string> split(const std::string& s, const std::string& delim) {
  std::vector<std::string> elems;
  size_t begin = 0, end = 0;
  while ((end = s.find(delim, begin)) != std::string::npos) {
    elems.push_back(s.substr(begin, end - begin));
    begin = end + delim.size();
  }
  elems.push_back(s.substr(begin));
  return elems;
}

std::string rstrip(const std::string& s) {
  if (s.empty()) { return s; }
  size_t i = s.size();
  while (s[i - 1] == ' ') { i--; }
  return s.substr(0, i);
}

bool startswith(const std::string& s, const std::string& prefix) {
  return s.substr(0, prefix.size()) == prefix;
}

auto check_and_get_parts(const std::string& s, bool no_tty = false) {
  static const std::string crcl = "\r\033[K";
  if (not no_tty) { REQUIRE(startswith(s, crcl)); }
  REQUIRE(s.back() == '\n');

  auto parts =
      no_tty ? split(s.substr(0, s.size() - 1), '\n')
             : split(s.substr(crcl.size(), s.size() - 1 - crcl.size()), crcl);
  CHECK(not parts.empty());
  return parts;
}

void check_anim(const std::vector<std::string>& parts,
                const std::string& msg,
                const std::vector<std::string>& stills) {
  for (size_t i = 0; i < parts.size() - 1; i++) {
    size_t j = i % stills.size();
    auto& part = parts[i];
    CHECK(part == (msg + " " + stills[j] + " "));
  }
}

TEST_CASE("Animation default", "[anim]") {
  auto anim = Animation();
  anim.done();
}

TEST_CASE("Animation", "[anim]") {
  std::stringstream out;

  auto sty = GENERATE(Ellipsis, Clock, Moon, Earth, Bar, Square);
  auto no_tty = GENERATE(true, false);
  auto interval = GENERATE(as<std::variant<Duration, double>>(), 100ms, 0.1);

  auto anim = Animation({
      .out = &out,
      .message = "Working",
      .style = sty,
      .interval = interval,
      .no_tty = no_tty,
  });

  anim.show();
  std::this_thread::sleep_for(1s);
  anim.done();

  auto parts = check_and_get_parts(out.str(), no_tty);
  check_anim(parts, "Working", animation_stills_[size_t(sty)]);
}

using ProgressTypeList =
    std::tuple<size_t, std::atomic<size_t>, int, unsigned, float, double>;

TEMPLATE_LIST_TEST_CASE("Counter default", "[counter]", ProgressTypeList) {
  using ValueType = value_t<TestType>;
  TestType amount{GENERATE(as<ValueType>(), 0, 3)};

  auto ctr = Counter(&amount);
  ctr.done();
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
  ctr.show();
  for (size_t i = 0; i < 101; i++) {
    std::this_thread::sleep_for(0.13ms);
    // no work
  }
  ctr.done();

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

template <typename Value>
auto extract_counts(const std::string& prefix,
                    const std::vector<std::string>& parts) {
  std::vector<Value> rval;
  for (auto& part : parts) {
    REQUIRE(part.substr(0, prefix.size()) == prefix);
    size_t i = part.find_first_of(' ', prefix.size());
    auto countstr = part.substr(prefix.size(), i - prefix.size());
    rval.push_back(Value(std::stod(countstr)));
  }

  return rval;
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
  ctr.show();

  ValueType increment = ValueType(1.2); // becomes 1 for integral types
  for (size_t i = 0; i < 101; i++) {
    std::this_thread::sleep_for(1.3ms);
    amount += increment;
  }
  ctr.done();

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
  ctr.show();

  for (size_t i = 0; i < 101; i++) {
    std::this_thread::sleep_for(1.3ms);
    amount--;
  }
  ctr.done();

  auto parts = check_and_get_parts(out.str());
  auto counts = extract_counts<int>("Doing things ", parts);

  for (size_t i = 1; i < counts.size(); i++) {
    CHECK(counts[i] <= counts[i - 1]);
  }

  // Final result should always be displayed
  CHECK(counts.back() == 0);
}

template <typename Display>
Display factory_helper();

template <>
Animation factory_helper<Animation>() {
  static std::stringstream hide;
  return Animation({&hide});
}

template <>
Counter<> factory_helper<Counter<>>() {
  static size_t progress;
  static std::stringstream hide;
  return Counter(&progress, {.out = &hide, .speed = 1});
}

template <>
ProgressBar<float> factory_helper<ProgressBar<float>>() {
  static float progress;
  static std::stringstream hide;
  return ProgressBar(&progress, {.out = &hide, .speed = 1});
}

template <>
Composite factory_helper<Composite>() {
  static size_t progress;
  static std::stringstream hide;
  return ProgressBar(&progress, {.out = &hide, .speed = 1}) |
         Counter(&progress, {.out = &hide, .speed = 1});
}

using DisplayTypes =
    std::tuple<Animation, Counter<>, ProgressBar<float>, Composite>;

TEMPLATE_LIST_TEST_CASE("Error cases", "[edges]", DisplayTypes) {
  auto orig = factory_helper<TestType>();
  orig.show();
  SECTION("Running copy & move") {
    //CHECK_THROWS([&]() { auto copy{orig}; }());
    CHECK_THROWS([&]() { auto copy{std::move(orig)}; }());
  }
  SECTION("Running compose") {
    // This fails because copy / move is needed and they will both throw
    CHECK_THROWS([&]() { orig | orig; }());
    CHECK_THROWS([&]() { orig | orig | orig; }());
  }
  // This is now a no-op, instead of error.
  CHECK_NOTHROW(orig.show());
  orig.done();
  CHECK_NOTHROW(orig.done());
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
      display.show();
    }
  }());
}

TEMPLATE_LIST_TEST_CASE("Copy & move", "[edges]", DisplayTypes) {
  CHECK_NOTHROW([]() {
    auto orig = factory_helper<TestType>();
    //auto copy = orig;
    auto moved = std::move(orig);
    //copy.show();
    //copy.done();
    moved.show();
    moved.done();
  }());
}

TEMPLATE_LIST_TEST_CASE("Clone", "[edges]", DisplayTypes) {
  CHECK_NOTHROW([]() {
    auto orig = factory_helper<TestType>();
    auto clone = orig.clone();
    clone->show();
    clone->done();
  }());
}

void check_shrinking_space(const Strings& parts, ProgressBarStyle sty) {
  // Check that space is shrinking
  size_t last_spaces = std::numeric_limits<size_t>::max();
  size_t first_spaces = std::numeric_limits<size_t>::max();
  for (auto& part : parts) {
    size_t spaces;
    if (sty != Pip) {
      spaces = size_t(std::count(part.begin(), part.end(), ' '));
    } else {
      size_t left = part.find(progress_bar_parts_[size_t(sty)].middle_modifier);
      size_t right =
          part.find(progress_bar_parts_[size_t(sty)].right_modifier, left);
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

TEMPLATE_LIST_TEST_CASE("Progress bar", "[bar]", ProgressTypeList) {
  std::stringstream out;
  TestType progress{0};

  bool no_tty = GENERATE(true, false);
  auto sty = GENERATE(Bars, Blocks, Arrow, Pip);

  auto bar = ProgressBar(&progress,
                         {
                             .out = &out,
                             .total = 50,
                             .message = "Computing",
                             .style = sty,
                             .interval = 0.001s,
                             .no_tty = no_tty,
                         });
  bar.show();
  for (size_t i = 0; i < 50; i++) {
    std::this_thread::sleep_for(1.3ms);
    progress++;
  }
  bar.done();

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

  // bool no_tty = GENERATE(true, false);
  auto sty = GENERATE(Bars, Blocks, Arrow, Pip);

  for (auto& thing : IterableBar(things,
                                 {
                                     .out = &out,
                                    .message = "Computing",
                                    .style = sty,
                                    .interval = 0.001s,
                                 })) {
    dummy_sum += thing;
    std::this_thread::sleep_for(1.3ms);
  }

  CHECK(dummy_sum == 150);

  auto parts = check_and_get_parts(out.str(), false);

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
  auto sty = GENERATE(Bars, Blocks, Arrow, Pip);
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

  bar.show();
  for (size_t i = 0; i < 50; i++) {
    std::this_thread::sleep_for(1.3ms);
    progress++;
  }
  bar.done();

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

  // bool no_tty = GENERATE(true, false);
  // auto default_speed_unit = GENERATE(true, false);

  auto sty = GENERATE(Bars, Blocks, Arrow, Pip);

  for (auto& thing : IterableBar(things,
                                 {
                                     .out = &out,
                                    .message = "Computing",
                                    .speed = 1,
                                    .speed_unit = "thing/time",
                                    .style = sty,
                                    .interval = 0.001s,
                                 })) {
    std::this_thread::sleep_for(1.3ms);
    dummy_sum += thing;
  }

  CHECK(dummy_sum == 150);

  auto parts = check_and_get_parts(out.str());

  // Check that message is correct
  for (auto& part : parts) { CHECK(part.substr(0, 10) == "Computing "); }

  // Check speed unit
  for (auto& part : parts) {
    CHECK(part.find("it/s") == std::string::npos);
    CHECK(part.find("thing/time") != std::string::npos);
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
                         });

  SECTION("Above") {
    progress = 50;
    bar.show();
    for (size_t i = 0; i < 50; i++) {
      std::this_thread::sleep_for(1.3ms);
      progress++;
    }
    bar.done();

    auto parts = check_and_get_parts(out.str());
    for (auto part : parts) {
      CHECK(part.find(std::string(32, '|')) != std::string::npos);
    }
  }

  SECTION("Below") {
    progress = 0;
    bar.show();
    for (size_t i = 0; i < 50; i++) {
      std::this_thread::sleep_for(1.3ms);
      progress--;
    }
    bar.done();

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
                         }) |
             Counter(&toks,
                     {
                         .out = &out,
                         .message = "Toks",
                         .speed = 1,
                         .speed_unit = "tok/s",
                     });
  bar.show();
  for (int i = 0; i < 505; i++) {
    std::this_thread::sleep_for(0.13ms);
    sents++;
    toks += size_t(1 + rand() % 5);
  }
  bar.done();

  auto parts = check_and_get_parts(out.str());
  long last_spaces = std::numeric_limits<long>::max(), last_count = 0;

  for (auto& part : parts) {
    CHECK(part.substr(0, 6) == "Sents ");
    CHECK(part.substr(54, 7) == "  Toks ");
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
      auto count_part = part.substr(61, part.size());
      auto i = count_part.find_first_of(' ');
      long count = std::stol(count_part.substr(0, i));
      CHECK(count >= last_count);
      last_count = count;
    }
  }
}