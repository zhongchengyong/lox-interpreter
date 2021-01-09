//
// Created by kode.zhong on 2021/1/9.
//
#include "test_parser.h"

ParserTest::ParserTest() = default;

ParserTest::~ParserTest() = default;

void ParserTest::SetUp() {
  Test::SetUp();
}

void ParserTest::TearDown() {
  Test::TearDown();
}

std::string ParserTest::VisitLiteral(Literal& literal) {
  return std::any_cast<std::string>(m_ast_printer.VisitLiteral(literal));
}

TEST_F(ParserTest, Literal) {
  Literal literal;
  LoxToken lox_token{TokenType::MINUS, "-", "", 1};
  literal.m_value = lox_token;
  assert(VisitLiteral(literal) == "(-)");
}
