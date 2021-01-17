//
// Created by kode.zhong on 2021/1/15.
//

#ifndef LOX_INTERPRETER_COMMON_EXCEPTION_H_
#define LOX_INTERPRETER_COMMON_EXCEPTION_H_
#include <exception>
#include <utility>

namespace lox {
class RuntimeError : public std::runtime_error {
 public:
  RuntimeError(LoxToken token, const std::string &msg) : std::runtime_error{msg}, m_token{std::move(token)} {}
  [[nodiscard]] LoxToken GetToken() const { return m_token; }
 private:
  LoxToken m_token;
};
} //namespace lox

#endif //LOX_INTERPRETER_COMMON_EXCEPTION_H_
