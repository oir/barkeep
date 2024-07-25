#define CATCH_CONFIG_MAIN
#define FMT_HEADER_ONLY
#ifndef BARKEEP_ENABLE_FMT_FORMAT
#define BARKEEP_ENABLE_FMT_FORMAT
#endif

#include <atomic>
#include <string>
#include <tuple>
#include <barkeep/barkeep.h>
#include <catch2/catch.hpp>

#include "testutil.h"

using namespace std::chrono_literals;
using namespace barkeep;

using ProgressTypeList =
    std::tuple<size_t, std::atomic<size_t>, int, unsigned, float, double>;

TEMPLATE_LIST_TEST_CASE("Counter constant", "[counter]", ProgressTypeList) {
  std::stringstream out;

  using ValueType = value_t<TestType>;

  TestType amount{GENERATE(as<ValueType>(), 0, 3)};
  auto sp = GENERATE(as<std::optional<double>>(), std::nullopt, 1);
  std::string unit = GENERATE("", "thing/10ms");

  std::string value_fmt =
      std::is_floating_point_v<ValueType> ? "{value:.2f}" : "{value}";

  std::string fmtstr;
  if (not sp) {
    fmtstr = "Doing things " + value_fmt;
  } else {
    if (unit.empty()) {
      fmtstr = "Doing things " + value_fmt + " ({speed:.2f})";
    } else {
      fmtstr = "Doing things " + value_fmt + " ({speed:.2f} " + unit + ")";
    }
  }

  auto ctr = Counter(
      &amount, {.out = &out, .format = fmtstr, .speed = sp, .interval = 0.001});
  ctr->show();
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

  std::string value_fmt =
      std::is_floating_point_v<ValueType> ? "{value:.2f}" : "{value}";
  std::string fmtstr;
  if (not sp) {
    fmtstr = "Doing things " + value_fmt;
  } else {
    if (unit.empty()) {
      fmtstr = "Doing things " + value_fmt + " ({speed:.2f})";
    } else {
      fmtstr = "Doing things " + value_fmt + " ({speed:.2f} " + unit + ")";
    }
  }

  auto ctr = Counter(&amount,
                     {.out = &out,
                      .format = fmtstr,
                      .speed = sp,
                      .interval = 0.001,
                      .no_tty = no_tty});
  ctr->show();

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

TEMPLATE_LIST_TEST_CASE("Progress bar", "[bar]", ProgressTypeList) {
  std::stringstream out;
  TestType progress{0};

  bool no_tty = GENERATE(true, false);

  using ValueType = value_t<TestType>;
  std::string value_fmt =
      std::is_floating_point_v<ValueType> ? "{value:.2f}" : "{value:2d}";

  auto bar = ProgressBar(&progress,
                         {
                             .out = &out,
                             .total = 50,
                             .format = "Computing {percent:6.2f}%) {bar} " +
                                       value_fmt + "/{total}",
                             .speed = 0.9,
                             .style = GENERATE(Bars, Blocks),
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

  // Check that space is shrinking
  size_t last_spaces = std::numeric_limits<size_t>::max();
  for (auto& part : parts) {
    auto spaces = size_t(std::count(part.begin(), part.end(), ' '));
    CHECK(spaces <= last_spaces);
    last_spaces = spaces;
  }
}

TEST_CASE("Progress bar out-of-bounds", "[bar][edges]") {
  std::stringstream out;
  int progress;
  auto bar = ProgressBar(
      &progress,
      {
          .out = &out,
          .total = 50,
          .format = "Computing {percent:6.2f}%) {bar} {value:2d}/{total}",
          .style = Bars,
          .interval = 0.001,
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

TEST_CASE("Composite bar-counter", "[composite]") {
  std::stringstream out;

  std::atomic<size_t> sents{0}, toks{0};
  auto bar =
      ProgressBar(
          &sents,
          {
              .out = &out,
              .total = 505,
              .format = "Sents {percent:6.2f}% {bar} {value:3d}/{total:3d}",
              .style = Bars,
              .interval = 0.01,
              .show = false,
          }) |
      Counter(&toks,
              {.out = &out,
               .format = "Toks {value}  ({speed:.2f} tok/s)",
               .speed = 1,
               .show = false});

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