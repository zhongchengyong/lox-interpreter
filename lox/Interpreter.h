//
// Created by kode.zhong on 2021/1/10.
//

#ifndef LOX_INTERPRETER_LOX_INTERPRETER_H_
#define LOX_INTERPRETER_LOX_INTERPRETER_H_

#include "visitor.h"

namespace lox {

/**
 * The lox Interpreter for Expression.
 */
class Interpreter : public ExprVisitor {
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
  void Interpret(Expr &expr);
 private:
  /**
   * The helper function which simply send the expression back into the Interpreter's visitor implementation.
   */
  std::any Evaluate(Expr &expr);
  static bool IsTruthy(const std::any &obj);
  static bool IsEqual(const std::any &any, const std::any &any_1);
};
}

#endif //LOX_INTERPRETER_LOX_INTERPRETER_H_
