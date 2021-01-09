//
// Created by kode.zhong on 2021/1/9.
//

#ifndef LOX_INTERPRETER_TEST_TESTLOX_TEST_PARSER_H_
#define LOX_INTERPRETER_TEST_TESTLOX_TEST_PARSER_H_

#include <gtest/gtest.h>

#include "lox/expr.h"
#include "lox/ast_printer.h"

using namespace lox;

class ParserTest: public ::testing::Test {
 private:
  AstPrinter m_ast_printer;
 protected:
  ParserTest();
  ~ParserTest() override;
  void SetUp() override;
  void TearDown() override;
 public:
  std::string VisitLiteral(Literal& literal);
};

#endif //LOX_INTERPRETER_TEST_TESTLOX_TEST_PARSER_H_
