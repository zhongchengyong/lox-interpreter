//
// Created by kode.zhong on 2020/12/27.
//

#ifndef LOX_INTERPRETER_LOX_EXPR_H_
#define LOX_INTERPRETER_LOX_EXPR_H_

#include <any>
#include <boost/preprocessor.hpp>

#include "lexer.h"
#include "common/generater.h"
#include "visitor.h"

namespace lox {

/**
 * The base class for expression.
 */
struct Expr {
  // TODO(zhongcy): C++ do NOT support template member function as virtual, use any instead.
  virtual std::any Accept(ExprVisitor &visitor) = 0;
};

using Expr_up = std::unique_ptr<Expr>;

DEFINE_EXPR_TYPE(Assign, (LoxToken) (Expr_up), (name)(value))
DEFINE_EXPR_TYPE(Binary, (Expr_up) (LoxToken) (Expr_up), (left)(op)(right))
DEFINE_EXPR_TYPE(Call, (Expr_up) (LoxToken) (std::vector<Expr_up>), (callee)(paren)(arguments))
DEFINE_EXPR_TYPE(Get, (Expr_up) (LoxToken), (object)(name))
DEFINE_EXPR_TYPE(Grouping, (Expr_up), (expression))
DEFINE_EXPR_TYPE(Literal, (LoxToken), (value))
DEFINE_EXPR_TYPE(Logical, (Expr_up) (LoxToken) (Expr_up), (left)(op)(right))
DEFINE_EXPR_TYPE(Set, (Expr_up) (LoxToken) (Expr_up), (object)(name)(value))
DEFINE_EXPR_TYPE(Super, (LoxToken) (LoxToken), (keyword)(method))
DEFINE_EXPR_TYPE(This, (LoxToken), (keyword))
DEFINE_EXPR_TYPE(Unary, (LoxToken) (Expr_up), (op)(right))
DEFINE_EXPR_TYPE(Variable, (LoxToken), (name))

} // namespace lox

#endif //LOX_INTERPRETER_LOX_EXPR_H_
