//============== scanner.cc - Implementacao ==============//
//
//               The pascc compiler
//
// Implementacao do arquivo /include/scanner.h
//
//============== -------------------------- ==============//

#include "../../include/lex/scanner.h"

unsigned int line = 1;
char buffer;
bool is_buffer = false;

bool IsKeyWord(const std::string& word) {
  if(word==kw::kProgram or word==kw::kVar or word==kw::kInteger or word==kw::kReal or
     word==kw::kBoolean or word==kw::kProcedure or word==kw::kBegin or word==kw::kEnd or
     word==kw::kIf or word==kw::kThen or word==kw::kElse or word==kw::kWhile or
     word==kw::kDo or word==kw::kNot) return true;
  else
    return false;
}

inline void SetBuffer(char ch){
  buffer = ch;
  is_buffer = true;
}

Scanner::Scanner(FILE* file): stream(file) {}

Scanner::~Scanner(){ fclose(stream); }

char Scanner::GetNextChar() {
  if(is_buffer){
    is_buffer = false;
    return buffer;
  } else {
    return getc(this->stream);
  }
}

void Scanner::LexerError(std::string e) const {
  fprintf(stderr, "\n@@ Lexer error message: %s\n", e.c_str());
  // exit(1); opcional
}

void Scanner::PrintToken() const {
  int len = token.size();

  for(int i = 0 ; i < len; ++i){
    printf("Token category: %s \tLexeme: %s\tLine: %d\n", kGetStrType.at(token.at(i).type),
          (token.at(i).lexeme).c_str(), token.at(i).line);
  }
}

bool Scanner::BuildToken() {
  bool done = false;

  while(not done){
    char ch = GetNextChar();
    // ignora linha | isspace() nao captura apenas espacos em branco
    while(std::isspace(ch)){
      if(ch=='\n') ++line;
      ch = GetNextChar();
    }
    switch (ch) {
      case '{': {
        while(ch!='}'){
          ch = GetNextChar();
          if(ch==EOF){
            SetBuffer(ch);
            LexerError("unterminated comment miss '}'");
            break;
          }
        }
        break;
      }
      case '+': case '-': {
        this->token.push_back(Token{std::string(1, ch), line, Type::kAddOperator});
        break;
      }
      case '*': case '/': {
        this->token.push_back(Token{std::string(1, ch), line, Type::kMulOperator});
        break;
      }
      case ';': case '.': case '(': case ')': {
        this->token.push_back(Token{std::string(1, ch), line, Type::kDelimiter});
        break;
      }
      case '<':  case '>': {
        std::string lexeme(1, ch);
        ch = GetNextChar();

        if(ch=='=' or (ch=='>' and lexeme=="<"))
          lexeme += ch;
        else
          SetBuffer(ch);
        this->token.push_back(Token{lexeme, line, Type::kRelOperator});
        break;
      }
      case '=': {
        this->token.push_back(Token{"=", line, Type::kRelOperator});
        break;
      }
      case ':': {
        ch = GetNextChar();
        if(ch=='='){
          this->token.push_back(Token{":=", line, Type::kCommand});
        } else {
          this->token.push_back(Token{":", line, Type::kDelimiter});
          SetBuffer(ch);
        }
        break;
      }
      case EOF: {
        this->token.push_back(Token{"EOF", line, Type::kEOF});
        done = true;
        break;
      }
      default: {
        if(std::isdigit(ch)){
          Type type = Type::kIntLiteral;
          std::string number(1, ch);
          ch = GetNextChar();

          while(std::isdigit(ch)){
            number += ch;
            ch = GetNextChar();
          }
          if(ch=='.') {
            number += ch;
            ch = GetNextChar();
            if(not isdigit(ch))
              LexerError("expected a digit after '.'");
            type = kRealLiteral;
            do {
              number += ch;
              ch = GetNextChar();
            } while(isdigit(ch));
          }
          this->token.push_back(Token{number, line, type});
          SetBuffer(ch);

        } else if (std::isalpha(ch)) {
          Type type = Type::kIdentifier;
          std::string word(1, ch);
          ch = GetNextChar();

          while(std::isalnum(ch) or ch=='_'){
            word += ch;
            ch = GetNextChar();
          }
          if(IsKeyWord(word))
            type = Type::kKeyword;

          this->token.push_back(Token{word, line, type});
          SetBuffer(ch);

        } else {
          LexerError("unexpected token "+ch);
        }
      }
    }
  }
}
