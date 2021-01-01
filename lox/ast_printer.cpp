//
// Created by kode.zhong on 2020/12/27.
//

#include "ast_printer.h"
#include "expr.h"

std::any lox::AstPrinter::VisitAssign(lox::Assign &expr) {
  return Print("=", expr.m_name.m_lexeme, expr.m_value);
  // return Parenthesize("=", expr.m_name.m_lexeme, expr.m_value);
}
std::any lox::AstPrinter::VisitBinary(lox::Binary &expr) {
  return Print(expr.m_op.m_lexeme, expr.m_left, expr.m_right);
}
std::any lox::AstPrinter::VisitCall(lox::Call &expr) {
  return std::any();
}
std::any lox::AstPrinter::VisitGet(lox::Get &expr) {
  return std::any();
}
std::any lox::AstPrinter::VisitGrouping(lox::Grouping &expr) {
  return std::any();
}
std::any lox::AstPrinter::VisitLiteral(lox::Literal &expr) {
  return Print(expr.m_value.m_lexeme);
}
std::any lox::AstPrinter::VisitLogical(lox::Logical &expr) {
  return std::any();
}
std::any lox::AstPrinter::VisitSet(lox::Set &expr) {
  return std::any();
}
std::any lox::AstPrinter::VisitSuper(lox::Super &expr) {
  return std::any();
}
std::any lox::AstPrinter::VisitThis(lox::This &expr) {
  return std::any();
}
std::any lox::AstPrinter::VisitUnary(lox::Unary &expr) {
  return std::any();
}
std::any lox::AstPrinter::VisitVariable(lox::Variable &expr) {
  return std::any();
}
