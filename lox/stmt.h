//
// Created by kode.zhong on 2020/12/27.
//

#ifndef LOX_INTERPRETER_LOX_STMT_H_
#define LOX_INTERPRETER_LOX_STMT_H_

#include <any>

#include "lexer.h"
#include "common/generater.h"
#include "visitor.h"

namespace lox {



/**
 * The base class for statement.
 */
struct Stmt {
  virtual std::any Accept(StmtVisitor &visitor) = 0;
};

using Stmt_up = std::unique_ptr<Stmt>;

// TODO(zhongcy): Add other stmt types
DEFINE_STMT_TYPE(BlockStmt, (std::vector<Stmt_up>), (statements))

} // namespace lox


#endif //LOX_INTERPRETER_LOX_STMT_H_
