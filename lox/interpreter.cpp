//
// Created by kode.zhong on 2021/1/10.
//

#include "expr.h"
#include "interpreter.h"
#include "exception.h"

#define UNREACHABLE_CONDITION assert(false && "Unreachable")

std::any lox::interpreter::VisitAssign(lox::Assign &expr) {
  return std::any();
}
std::any lox::interpreter::VisitBinary(lox::Binary &expr) {
  std::any left = Evaluate(*expr.m_left);
  std::any right= Evaluate(*expr.m_right);
  switch (expr.m_op.m_type) {
    case TokenType::MINUS:
      return std::any_cast<double>(left) - std::any_cast<double>(right);
    case TokenType::SLASH:
      return std::any_cast<double>(left) / std::any_cast<double>(right);
    case TokenType::STAR:
      return std::any_cast<double>(left) * std::any_cast<double>(right);
    case TokenType::PLUS:
      if (left.type() == typeid(double) && right.type() == typeid(double)) // number plus
        return std::any_cast<double>(left) + std::any_cast<double>(right);
      if (left.type() == typeid(std::string) && right.type() == typeid(std::string)) // string plus
        return std::any_cast<std::string>(left) + std::any_cast<std::string>(right);
      throw RuntimeError(expr.m_op, "the '+' operator type must be same");
  }
  UNREACHABLE_CONDITION;
}
std::any lox::interpreter::VisitCall(lox::Call &expr) {
  return std::any();
}
std::any lox::interpreter::VisitGet(lox::Get &expr) {
  return std::any();
}

std::any lox::interpreter::VisitGrouping(lox::Grouping &expr) {
  return Evaluate(*expr.m_expression);
}

std::any lox::interpreter::VisitLiteral(lox::Literal &expr) {
  return expr.m_value;
}

std::any lox::interpreter::VisitLogical(lox::Logical &expr) {
  return std::any();
}

std::any lox::interpreter::VisitSet(lox::Set &expr) {
  return std::any();
}

std::any lox::interpreter::VisitSuper(lox::Super &expr) {
  return std::any();
}

std::any lox::interpreter::VisitThis(lox::This &expr) {
  return std::any();
}

std::any lox::interpreter::VisitUnary(lox::Unary &expr) {
  std::any right = Evaluate(*expr.m_right);
  switch (expr.m_op.m_type) {
    case TokenType::MINUS:
      return -std::any_cast<double>(right);
    case TokenType::BANG:
      return !IsTruthy(right);
    default:
      return std::any_cast<std::string>(right);
  }
  UNREACHABLE_CONDITION;
}

std::any lox::interpreter::VisitVariable(lox::Variable &expr) {
  return std::any();
}

std::any lox::interpreter::Evaluate(lox::Expr &expr) {
  return expr.Accept(*this);
}

bool lox::interpreter::IsTruthy(std::any obj) {
  if (!obj.has_value()) return false;
  if (obj.type() == typeid(bool)) return std::any_cast<bool>(obj);
  return true;
}
