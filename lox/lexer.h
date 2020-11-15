//
// Created by kode.zhong on 2020/11/14.
//

#ifndef LOX_INTERPRETER_LOX_LEXER_H_
#define LOX_INTERPRETER_LOX_LEXER_H_

#include <string>

#include "common/logger.h"

namespace lox_lex {

class Lexer {
 public:
  Lexer() = default;
  void ScanTokens(const std::string &source);
};
}

#endif //LOX_INTERPRETER_LOX_LEXER_H_
