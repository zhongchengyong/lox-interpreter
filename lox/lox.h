//
// Created by kode.zhong on 2020/11/9.
//

#ifndef LOX_INTERPRETER_LOX_LOX_H_
#define LOX_INTERPRETER_LOX_LOX_H_

#include <string>

#include "lexer.h"
#include "exception.h"
#include "Interpreter.h"

namespace lox {
class Lox {
 public:
  void RunPrompt();
  void RunFile(const std::string &file_name);
  void Run(const std::string &source);
  static void RunTimeError(const RuntimeError& error);

 private:
  static std::unique_ptr<Interpreter> interp_up = std::make_unique<Interpreter>();
  // Indicate if error occurs
  static bool m_had_error;
  static bool m_has_runtime_error;

};
} // namespace lox

#endif //LOX_INTERPRETER_LOX_LOX_H_
