//
// Created by kode.zhong on 2020/11/9.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "lox.h"

using namespace lox_lex;

void Lox::RunPrompt() {
  std::string input;
  while (true) {
    std::cin >> input;
    if (input == "q") break;

  }
}

void Lox::RunFile(const std::string& file_name) {
  Lexer lexer;
  std::ifstream is(file_name);
  if (!is) {
    LOG_ERROR << "File not exists." << std::endl;
    assert(false);
  }
  std::stringstream ss;
  ss << is.rdbuf();
  lexer.ScanTokens(ss.str());
}
