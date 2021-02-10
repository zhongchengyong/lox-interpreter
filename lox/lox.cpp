//
// Created by kode.zhong on 2020/11/9.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "lox.h"

using namespace lox;

bool Lox::m_had_error = false;
bool Lox::m_has_runtime_error = false;


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
  if (m_had_error) exit(65);
  if (m_has_runtime_error) exit(70);
}

void Lox::Run(const std::string &source) {
  Lexer lexer(source);
  lexer.ScanTokens();
  if (m_had_error) return;
  interp_up->Interpret()
}

void Lox::RunTimeError(const RuntimeError &error) {
  std::cerr << error.what() << "\n[line " << error.GetToken().m_line << "]" << std::endl;

}
