//
// Created by kode.zhong on 2020/11/14.
//

#ifndef LOX_INTERPRETER_LOX_LEXER_H_
#define LOX_INTERPRETER_LOX_LEXER_H_

#include <string>
#include <utility>
#include <vector>
#include <unordered_map>

#include "common/logger.h"

namespace lox {

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
  Token(TokenType type, std::string lexeme, const T &literal, uint32_t line) :
      m_type{type}, m_lexeme{std::move(lexeme)}, m_literal(literal), m_line(line){}
  // Token type
  const TokenType m_type;
  const std::string m_lexeme;
  const T m_literal;
  uint32_t m_line;
  friend std::ostream& operator << (std::ostream& os, const Token& token);
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Token<T> &token) {
  os << token;
  return os;
}

using LoxToken = Token<std::string>;

/**
 * Lox language lexer, corresponding to Scanner.java.
 */
class Lexer {
 public:
  explicit Lexer(std::string source) : m_source{std::move(source)} {}
  void ScanTokens();
 private:
  std::string m_source;
  std::vector<LoxToken> m_tokens;

  // Scan state
  uint32_t m_start = 0;
  uint32_t m_cur = 0;
  uint32_t m_line = 1;

  static std::unordered_map<std::string, TokenType> m_keywords;

  bool IsAtEnd() {
    return m_cur == m_source.size();
  }

  void AddToken(TokenType type);
  template <typename T>
  void AddToken(TokenType type, const T &literal);
  char Advance();
  void scanToken();
  bool Match(char expected);
  char LookForward(int pos = 0);
  bool IsDigit(char c);
  void AddNumber();
  bool IsAlpha(char c);
  void AddIdentifier();
  bool IsAlphaNumeric(char forward);
};



} // namespace lox

#endif //LOX_INTERPRETER_LOX_LEXER_H_
