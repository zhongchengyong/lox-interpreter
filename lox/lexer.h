//
// Created by kode.zhong on 2020/11/14.
//

#ifndef LOX_INTERPRETER_LOX_LEXER_H_
#define LOX_INTERPRETER_LOX_LEXER_H_

#include <string>

#include "common/logger.h"

namespace lox {

class Lexer {
 public:
  explicit Lexer(const std::string &source) : m_source{source} {}
  void ScanTokens();
 private:
  std::string m_source;
};

/**
 * Lox language tokens.
 */
enum class TokenType {
  // Single-character tokens.
  LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
  COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

  // One or two character tokens.
  BANG, BANG_EQUAL,
  EQUAL, EQUAL_EQUAL,
  GREATER, GREATER_EQUAL,
  LESS, LESS_EQUAL,

  // Literals.
  IDENTIFIER, STRING, NUMBER,

  // Keywords.
  AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
  PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

  END
};

template <typename T>
struct Token {
  Token(TokenType type, std::string &lexeme, T &literal, int line) :
      m_type{type}, m_lexeme{lexeme}, m_literal(literal), m_line(line){}
  // Token type
  const TokenType m_type;
  const std::string m_lexeme;
  const T m_literal;
  size_t m_line;
  friend std::ostream& operator << (std::ostream& os, const Token& token);
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Token<T> &token) {
  os << token;
  return os;
}

using LoxToken = Token<std::string>;

} // namespace lox

#endif //LOX_INTERPRETER_LOX_LEXER_H_
