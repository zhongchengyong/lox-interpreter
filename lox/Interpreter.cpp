//
// Created by kode.zhong on 2021/1/10.
//

#include "expr.h"
#include "Interpreter.h"
#include "exception.h"
#include "lox.h"

#define UNREACHABLE_CONDITION assert(false && "Unreachable")

std::any lox::Interpreter::VisitAssign(lox::Assign &expr) {
  return std::any();
}
std::any lox::Interpreter::VisitBinary(lox::Binary &expr) {
  std::any left = Evaluate(*expr.m_left);
  std::any right= Evaluate(*expr.m_right);
  switch (expr.m_op.m_type) {
    case TokenType::GREATER:
      return std::any_cast<double>(left) > std::any_cast<double>(right);
    case TokenType::GREATER_EQUAL:
      return std::any_cast<double>(left) >= std::any_cast<double>(right);
    case TokenType::LESS:
      return std::any_cast<double>(left) < std::any_cast<double>(right);
    case TokenType::LESS_EQUAL:
      return std::any_cast<double>(left) <= std::any_cast<double>(right);
    case TokenType::BANG_EQUAL:
      return !IsEqual(left, right);
    case TokenType::EQUAL_EQUAL:
      return IsEqual(left, right);
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
std::any lox::Interpreter::VisitCall(lox::Call &expr) {
  return std::any();
}
std::any lox::Interpreter::VisitGet(lox::Get &expr) {
  return std::any();
}

std::any lox::Interpreter::VisitGrouping(lox::Grouping &expr) {
  return Evaluate(*expr.m_expression);
}

std::any lox::Interpreter::VisitLiteral(lox::Literal &expr) {
  return expr.m_value;
}

std::any lox::Interpreter::VisitLogical(lox::Logical &expr) {
  return std::any();
}

std::any lox::Interpreter::VisitSet(lox::Set &expr) {
  return std::any();
}

std::any lox::Interpreter::VisitSuper(lox::Super &expr) {
  return std::any();
}

std::any lox::Interpreter::VisitThis(lox::This &expr) {
  return std::any();
}

std::any lox::Interpreter::VisitUnary(lox::Unary &expr) {
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

std::any lox::Interpreter::VisitVariable(lox::Variable &expr) {
  return std::any();
}

std::string Stringify(const std::any& obj) {
  if (!obj.has_value()) return "nil";
  if (obj.type() == typeid(double)) {
    std::string text = std::to_string(std::any_cast<double>(obj));
    if (text.ends_with(".0")) {
      text = text.substr(0, text.size() - 2);
    }
    return text;
  }
  if (obj.type() == typeid(bool)) {
    return std::to_string(std::any_cast<bool>(obj));
  }
  return std::any_cast<std::string>(obj);
}

void lox::Interpreter::Interpret(lox::Expr &expr) {
  try {
    std::any obj = expr.Accept(*this);
    std::cout << Stringify(obj) << std::endl;
  }catch (const RuntimeError& error) {
    Lox::RuntimeError(error);
  }
}

std::any lox::Interpreter::Evaluate(lox::Expr &expr) {
  return expr.Accept(*this);
}

bool lox::Interpreter::IsTruthy(const std::any& obj) {
  if (!obj.has_value()) return false;
  if (obj.type() == typeid(bool)) return std::any_cast<bool>(obj);
  return true;
}

/**
 * Note: We have handled 3 types here.
 */
bool lox::Interpreter::IsEqual(const std::any& left, const std::any& right) {
  if (!left.has_value() && !right.has_value()) return true;
  if (left.type() != right.type()) return false;
  if (left.type() == typeid(bool)) {
    return std::any_cast<bool>(left) == std::any_cast<bool>(right);
  }
  if (left.type() == typeid(std::string)) {
    return std::any_cast<std::string>(left) == std::any_cast<std::string>(right);
  }
  if (left.type() == typeid(double)) {
    return std::any_cast<double>(left) == std::any_cast<double>(right);
  }
  return false;
}

