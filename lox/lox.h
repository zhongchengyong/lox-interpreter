//
// Created by kode.zhong on 2020/11/9.
//

#ifndef LOX_INTERPRETER_LOX_LOX_H_
#define LOX_INTERPRETER_LOX_LOX_H_

#include <string>

#include "lexer.h"

namespace lox {
class Lox {
 public:
  void RunPrompt();
  void RunFile(const std::string &file_name);
  void Run(const std::string &source);

 private:
  // Indicate if error occurs
  static bool m_error;

};
} // namespace lox

#endif //LOX_INTERPRETER_LOX_LOX_H_
