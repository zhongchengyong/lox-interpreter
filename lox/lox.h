//
// Created by kode.zhong on 2020/11/9.
//

#ifndef LOX_INTERPRETER_LOX_LOX_H_
#define LOX_INTERPRETER_LOX_LOX_H_

#include <string>

#include "lexer.h"

class Lox {
 private:
  int i;
 public:
  void RunPrompt();
  void RunFile(const std::string& file_name);


};

#endif //LOX_INTERPRETER_LOX_LOX_H_
