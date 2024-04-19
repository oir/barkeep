#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>





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
  size_t chars = 0, tokens = 0;




  
  for (size_t i = 0; i < docs.size(); ++i) {
    std::cout << "Doc " << i << std::endl;
    process_document(docs[i], out,
                     chars, tokens);
  }


  std::cout << "Total: " << chars
            << tokens << std::endl;

  return 0;
}
