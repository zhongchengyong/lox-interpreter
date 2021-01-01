//
// Created by kode.zhong on 2020/12/27.
//

#ifndef LOX_INTERPRETER_LOX_AST_PRINTER_H_
#define LOX_INTERPRETER_LOX_AST_PRINTER_H_

#include <string>
#include <sstream>

#include "visitor.h"
#include "expr.h"

namespace lox {

class AstPrinter : public ExprVisitor {
 public:
  std::any VisitAssign(Assign &expr) override;
  std::any VisitBinary(Binary &expr) override;
  std::any VisitCall(Call &expr) override;
  std::any VisitGet(Get &expr) override;
  std::any VisitGrouping(Grouping &expr) override;
  std::any VisitLiteral(Literal &expr) override;
  std::any VisitLogical(Logical &expr) override;
  std::any VisitSet(Set &expr) override;
  std::any VisitSuper(Super &expr) override;
  std::any VisitThis(This &expr) override;
  std::any VisitUnary(Unary &expr) override;
  std::any VisitVariable(Variable &expr) override;
 private:
  template <typename T>
  void Parenthesize(std::stringstream &ss, T &t) {
    ss << t;
  }

  // Use the template variadic arguments to implement variadic arguments
  template <typename T, typename... R>
  void Parenthesize(std::stringstream &ss, T &t, R&... args) {
    ss << t << " ";
    Parenthesize(ss, args...);
  }

  template <typename T, typename... R>
  std::string Print(T &t, R&... r) {
    std::stringstream ss;
    ss << "(";
    Parenthesize(ss,  t, r...);
    ss << ")";
    return ss.str();
  }


// FIXME(zhongcy): Check whether implement correctly?
//  template <typename Args>
//  void Parenthesize(std::stringstream &ss, Args&... args) {
//    Parenthesize(ss, args...);
//  }

//  template <typename... Args>
//  void Parenthesize<>(std::stringstream &ss, Expr& expr, Args&... args) {
//    ss << " ";
//    ss << std::any_cast<std::string>(expr.Accept(*this));
//    Parenthesize(ss, args...);
//  }

//  template <typename Args>
//  void Parenthesize(std::stringstream &ss,  Args& args) {
//    ss << " ";
//    ss << str;
//    Parenthesize(ss, args);
//  }

//  template <>
//  void Parenthesize<>(std::stringstream &ss, Expr& expr) {
//    ss << " ";
//    ss << std::any_cast<std::string>(expr.Accept(*this));
//  }

//  template <>
//  void Parenthesize(std::stringstream &ss, std::string& arg) {
//    ss << " ";
//    ss << arg;
//  }

};
} // namespace lox

#endif //LOX_INTERPRETER_LOX_AST_PRINTER_H_
