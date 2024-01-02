#define CATCH_CONFIG_MAIN
#define FMT_HEADER_ONLY
#define BARKEEP_ENABLE_FMT

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

  auto ctr = Counter(&amount, &out).interval(0.001).speed(sp).fmt(fmtstr);
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

  auto ctr = Counter(&amount, &out).interval(0.01s).speed(sp).fmt(fmtstr);
  if (no_tty) { ctr.no_tty(); }
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

template <typename Display>
Display factory_helper();

template <>
Animation factory_helper<Animation>() {
  static std::stringstream hide;
  return Animation(&hide);
}

template <>
Counter<> factory_helper<Counter<>>() {
  static size_t progress;
  static std::stringstream hide;
  return Counter(&progress, &hide).speed(1);
}

template <>
ProgressBar<float> factory_helper<ProgressBar<float>>() {
  static float progress;
  static std::stringstream hide;
  return ProgressBar(&progress, &hide).speed(1);
}

template <>
Composite factory_helper<Composite>() {
  static size_t progress;
  static std::stringstream hide;
  return ProgressBar(&progress, &hide).speed(1) |
         Counter(&progress, &hide).speed(1);
}

using DisplayTypes =
    std::tuple<Animation, Counter<>, ProgressBar<float>, Composite>;

TEMPLATE_LIST_TEST_CASE("Progress bar", "[bar]", ProgressTypeList) {
  std::stringstream out;
  TestType progress{0};

  bool no_tty = GENERATE(true, false);

  using ValueType = value_t<TestType>;
  std::string value_fmt =
      std::is_floating_point_v<ValueType> ? "{value:.2f}" : "{value:2d}";

  auto bar =
      ProgressBar(&progress, &out)
          .total(50)
          .fmt("Computing {percent:6.2f}%) {bar} " + value_fmt + "/{total}")
          .interval(0.001s);
  bar.style(GENERATE(Bars, Blocks, Arrow));
  if (no_tty) { bar.no_tty(); }
  bar.show();
  for (size_t i = 0; i < 50; i++) {
    std::this_thread::sleep_for(1.3ms);
    progress++;
  }
  bar.done();

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
  auto bar = ProgressBar(&progress, &out)
                 .total(50)
                 .fmt("Computing {percent:6.2f}% {bar} {value:2d}/{total}  ")
                 .interval(0.001)
                 .style(Bars);

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

TEST_CASE("Composite bar-counter", "[composite]") {
  std::stringstream out;

  std::atomic<size_t> sents{0}, toks{0};
  auto bar =
      ProgressBar(&sents, &out)
          .total(505)
          .fmt("Sents {percent:6.2f}% {bar} {value:3d}/{total:3d}")
          .style(Bars)
          .interval(0.01) |
      // Counter(&toks, &out).message("Toks").speed_unit("tok/s").speed(1);
      Counter(&toks, &out).fmt("Toks {value}  ({speed:.2f} tok/s)").speed(1);

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