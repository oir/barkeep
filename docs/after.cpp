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

  size_t total_chars = 0;
  size_t total_tokens = 0;
  size_t i = 0;

  auto bar = bk::ProgressBar(&i).total(docs.size()) |
             bk::Counter(&total_tokens).message("Tokens") |
             bk::Counter(&total_chars).message("Chars");
  bar.show();

  for (i = 0; i < docs.size(); ++i) {

    process_document(docs[i], out,
                     total_chars,
                     total_tokens);
  }

  bar.done();

  std::cout << "Total: " << total_chars
            << total_tokens << std::endl;

  return 0;
}
