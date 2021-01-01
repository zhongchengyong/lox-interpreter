//
// Created by kode.zhong on 2020/12/27.
//

#ifndef LOX_INTERPRETER_LOX_VISITOR_H_
#define LOX_INTERPRETER_LOX_VISITOR_H_
#include <any>

namespace lox {

class Expr;
class Assign;
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
class Stmt;

/**
 * Visitor interface for visitor pattern.
 */
struct ExprVisitor {
  virtual std::any VisitAssign(Assign &expr) = 0;
  virtual std::any VisitBinary(Binary &expr) = 0;
  virtual std::any VisitCall(Call &expr) = 0;
  virtual std::any VisitGet(Get &expr) = 0;
  virtual std::any VisitGrouping(Grouping &expr) = 0;
  virtual std::any VisitLiteral(Literal &expr) = 0;
  virtual std::any VisitLogical(Logical &expr) = 0;
  virtual std::any VisitSet(Set &expr) = 0;
  virtual std::any VisitSuper(Super &expr) = 0;
  virtual std::any VisitThis(This &expr) = 0;
  virtual std::any VisitUnary(Unary &expr) = 0;
  virtual std::any VisitVariable(Variable &expr) = 0;
};

/**
 * Visitor interface for visitor pattern.
 */
struct StmtVisitor {
  virtual std::any VisitBlockStmt(Stmt &Stmt) = 0;
};


}

#endif //LOX_INTERPRETER_LOX_VISITOR_H_
