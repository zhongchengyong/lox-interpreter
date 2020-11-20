//
// Created by kode.zhong on 2020/11/9.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "lox.h"

using namespace lox;

void Lox::RunPrompt() {
  std::string input;
  while (true) {
    std::cin >> input;
    if (input == "q") break;
    Run(input);
  }
}

void Lox::RunFile(const std::string& file_name) {
  std::ifstream is(file_name);
  if (!is) {
    LOG_ERROR << "File not exists." << std::endl;
    assert(false);
  }
  std::stringstream ss;
  ss << is.rdbuf();
  Run(ss.str());
}

void Lox::Run(const std::string &source) {
  Lexer lexer;
  lexer.ScanTokens(source);
  if (m_error) return;
}
