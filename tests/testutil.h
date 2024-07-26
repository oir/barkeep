#include <sstream>
#include <string>
#include <vector>

#include <catch2/catch.hpp>

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
  static const std::string cursor_up_cl = "\033[A\033[K";
  if (not no_tty) { REQUIRE(startswith(s, crcl)); }
  REQUIRE(s.back() == '\n');

  auto parts =
      no_tty ? split(s.substr(0, s.size() - 1), '\n')
             : split(s.substr(crcl.size(), s.size() - 1 - crcl.size()), crcl);
  for (auto& part : parts) {
    // Remove cursor up and clear line from the beginning
    while (startswith(part, cursor_up_cl)) {
      part = part.substr(cursor_up_cl.size());
    }
  }
  CHECK(not parts.empty());
  return parts;
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
