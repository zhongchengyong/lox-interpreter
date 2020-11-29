//
// Created by kode.zhong on 2020/11/14.
//

#include "lexer.h"
using namespace lox_common;
using namespace lox;

std::unordered_map<std::string, TokenType> Lexer::m_keywords = {
    {"add",    TokenType::AND},
    {"class",  TokenType::CLASS},
    {"else",   TokenType::ELSE},
    {"false",  TokenType::FALSE},
    {"for",    TokenType::FOR},
    {"fun",    TokenType::FUN},
    {"if",     TokenType::IF},
    {"nil",    TokenType::NIL},
    {"or",     TokenType::OR},
    {"print",  TokenType::PRINT},
    {"return", TokenType::RETURN},
    {"super",  TokenType::SUPER},
    {"this",   TokenType::THIS},
    {"true",   TokenType::TRUE},
    {"var",    TokenType::VAR},
    {"while",  TokenType::WHILE}
};

void Lexer::ScanTokens() {
  LOG_INFO << "Begin scan tokens";
  while (!IsAtEnd()) {
    m_start = m_cur;
    scanToken();
  }
  LoxToken lox_token{TokenType::END, "", "", m_line};
}

void Lexer::AddToken(TokenType type) {
  AddToken(type, "");
}

template<typename T>
void Lexer::AddToken(TokenType type, const T &literal) {
  std::string text = m_source.substr(m_start, m_cur - m_start);
  m_tokens.emplace_back(type, text, literal, m_line);
}

char Lexer::Advance() {
  char value = m_source[m_cur];
  ++m_cur;
  return value;
}

void Lexer::scanToken() {
  char c = Advance();
  switch (c) {
    case '(' :AddToken(TokenType::LEFT_PAREN);
      break;
    case ')' :AddToken(TokenType::RIGHT_PAREN);
      break;
    case '{' : AddToken(TokenType::LEFT_BRACE);
      break;
    case '}' : AddToken(TokenType::RIGHT_BRACE);
      break;
    case ',' : AddToken(TokenType::COMMA);
      break;
    case '.' : AddToken(TokenType::DOT);
      break;
    case '-' : AddToken(TokenType::MINUS);
      break;
    case '+' : AddToken(TokenType::PLUS);
      break;
    case ';' : AddToken(TokenType::SEMICOLON);
      break;
    case '*' : AddToken(TokenType::STAR);
      break;
      // Two-char tokens
    case '!':AddToken(Match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
      break;
    case '=':AddToken(Match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
      break;
    case '<':AddToken(Match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
      break;
    case '>':AddToken(Match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
      break;
    case '/':
      if (Match('/')) {
        while (LookForward() != '\n' && !IsAtEnd()) Advance();
      } else {
        AddToken(TokenType::SLASH);
      }
    case ' ':
    case '\r':
    case '\t':break;
    case '\n':++m_line;
      break;
    case '"' : {
      while (LookForward() != '"' && !IsAtEnd()) {
        if (LookForward() == '\n') ++m_line;
        Advance();
      }
      if (IsAtEnd()) {
        LEX_ERROR(m_line, "unterminated string");
        break;
      }

      // The closing "
      Advance();
      AddToken(TokenType::STRING, m_source.substr(m_start + 1, m_cur - m_start - 2));
      break;
    }
    default:
      if (IsDigit(c)) {
        AddNumber();
      } else if (IsAlpha(c)) {
        AddIdentifier();
      } else {
        LEX_ERROR(m_line, "Unexpected character");
      }
      break;
  }
}

bool Lexer::Match(char expected) {
  if (IsAtEnd()) return false;
  if (m_source[m_cur] != expected) return false;

  ++m_cur;
  return true;
}

char Lexer::LookForward(int pos) {
  if (m_cur + pos > m_source.size()) return '\0';
  return m_source[(m_cur + pos)];
}

bool Lexer::IsDigit(char c) {
  return c >= '0' && c < '9';
}

bool Lexer::IsAlphaNumeric(char c) {
  return IsDigit(c) || IsAlpha(c);
}

bool Lexer::IsAlpha(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

void Lexer::AddNumber() {
  while (IsDigit(LookForward())) Advance();
  if (LookForward() == '.' && IsDigit(LookForward(1))) {
    Advance();
    while (IsDigit(LookForward())) Advance();
  }
  AddToken(TokenType::NUMBER, m_source.substr(m_start, m_cur - m_start));
}


void Lexer::AddIdentifier() {
  while (IsAlphaNumeric(LookForward()))
    Advance();
  std::string text = m_source.substr(m_start, m_cur - m_start);
  if (m_keywords.find(text) == m_keywords.end()) {
    AddToken(TokenType::IDENTIFIER);
  }
}

