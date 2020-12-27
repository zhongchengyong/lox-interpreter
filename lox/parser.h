//
// Created by kode.zhong on 2020/11/29.
//

#ifndef LOX_INTERPRETER_LOX_PARSER_H_
#define LOX_INTERPRETER_LOX_PARSER_H_

#include <any>
#include <boost/preprocessor.hpp>

#include "lexer.h"

namespace lox {

class Expr;
class Assign;
class Binary;
class Call;
class Get;
class Grouping;
class Literal;
class Logical;
class Set;
class Super;
class This;
class Unary;
class Variable;

#define DEFINE_VISIT_FUNC(TYPE) \
virtual std::any Visit##TYPE(TYPE &expr) = 0;

struct Visitor {
  DEFINE_VISIT_FUNC(Assign)
  DEFINE_VISIT_FUNC(Binary)
  DEFINE_VISIT_FUNC(Call)
  DEFINE_VISIT_FUNC(Get)
  DEFINE_VISIT_FUNC(Grouping)
  DEFINE_VISIT_FUNC(Literal)
  DEFINE_VISIT_FUNC(Logical)
  DEFINE_VISIT_FUNC(Set)
  DEFINE_VISIT_FUNC(Super)
  DEFINE_VISIT_FUNC(This)
  DEFINE_VISIT_FUNC(Unary)
  DEFINE_VISIT_FUNC(Variable)
};

using Expr_up = std::unique_ptr<Expr>;

struct Expr {
  // TODO(zhongcy): C++ do NOT support template member function as virtual, use any instead.
  virtual std::any Accept(Visitor &visitor) = 0;
};

#define DECLARE_DATA_MEMBER(R, TYPES, INDEX, NAME) \
BOOST_PP_SEQ_ELEM(INDEX,TYPES) BOOST_PP_CAT(m_,NAME);

#define DEFINE_MEMBER(TYPES, MEMBERS) \
BOOST_PP_SEQ_FOR_EACH_I(DECLARE_DATA_MEMBER, TYPES, MEMBERS)

#define DEFINE_EXPR_TYPE(NAME, TYPES, MEMBERS)\
struct NAME : public Expr {\
  DEFINE_MEMBER(TYPES, MEMBERS)\
  std::any Accept(Visitor& visitor) override {\
    return visitor.Visit##NAME(*this);\
  }\
};

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

#endif //LOX_INTERPRETER_LOX_PARSER_H_
