#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <barkeep/barkeep.h>

namespace bk = barkeep;

// tokenize by space
std::vector<std::string> tknz(std::string s) {
  std::vector<std::string> rval;
  std::istringstream iss(s);
  for (std::string word; iss >> word;) {
    rval.push_back(word);
  }
  return rval;
}

void process_document(const std::string& doc,
                      std::ofstream& out,
                      size_t& total_chars,
                      size_t& total_tokens) {
  auto tokens = tknz(doc);
  for (auto& token : tokens) {
     out << token << std::endl;
     total_chars += token.size();
     total_tokens++;
  }
  out << std::endl;
}

int main(int /*argc*/, char** /*argv*/) {
  std::vector<std::string> docs = {/*...*/};
  std::ofstream out("tokens.txt");
  size_t chars = 0, tokens = 0, i = 0;

  auto bar = bk::ProgressBar(&i, {.total=docs.size(), .show=false}) |
             bk::Counter(&tokens, {.message="Tokens", .show=false}) |
             bk::Counter(&chars, {.message="Chars", .show=false});
  bar->show();
  for (i = 0; i < docs.size(); ++i) {

    process_document(docs[i], out,
                     chars, tokens);
  }
  bar->done();

  std::cout << "Total: " << chars
            << tokens << std::endl;

  return 0;
}
