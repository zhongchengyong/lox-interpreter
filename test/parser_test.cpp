//
// Created by kode.zhong on 2020/12/30.
//
#include <gtest/gtest.h>

#include "lox/expr.h"
#include "lox/ast_printer.h"

using namespace lox;
TEST(PARSER, ASTPRINTER) {
  Literal literal;
  LoxToken lox_token{TokenType::MINUS, "-", "", 1};
  literal.m_value = lox_token;
  AstPrinter ast_printer;
  auto value = ast_printer.VisitLiteral(literal);
  assert(std::any_cast<std::string>(value) == "(-)");
}

