//
// Created by kode.zhong on 2021/1/15.
//

#ifndef LOX_INTERPRETER_COMMON_EXCEPTION_H_
#define LOX_INTERPRETER_COMMON_EXCEPTION_H_
#include <exception>

namespace lox {
class RuntimeError : public std::runtime_error {
 public:
  RuntimeError(const LoxToken &token, const std::string &msg) : std::runtime_error{msg}, m_token{token} {}
  LoxToken GetToken() const { return m_token; }
 private:
  LoxToken m_token;
};
};

#endif //LOX_INTERPRETER_COMMON_EXCEPTION_H_
