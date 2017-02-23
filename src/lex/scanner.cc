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

inline bool IsKeyWord(const std::string& word) {
  if(word=="program" or word=="var" or word=="integer" or word=="real" or
     word=="boolean" or word=="procedure" or word=="begin" or word=="end" or
     word=="if" or word=="then" or word=="else" or word=="while" or
     word=="do" or word=="not") return true;
  else
    return false;
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

void Scanner::PrintToken() const {
  int len = token.size();

  for(int i = 0 ; i < len; ++i){
    printf("Token category: %s \tLexeme: %s\tLine: %d\n", kGetStrType.at(token.at(i).type),
          (token.at(i).lexeme).c_str(), token.at(i).line);
  }
}

bool Scanner::ReadToken() {
  bool done = false;

  while(not done){
    char ch = GetNextChar();
    // ignora linha | isspace() nao captura apenas espacos em brancos
    while(ch==' ')
      ch = GetNextChar();
    // incrementa o contador de linhas
    while(ch=='\n'){
      ++line;
      ch = GetNextChar();
    }
    switch (ch) {
      case '{': {
        while(ch!='}'){
          ch = GetNextChar();
          if(ch==EOF){
            is_buffer = true;
            fprintf(stderr, "ERROR: Comentario esperado!\n");
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
          is_buffer = true;
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
          is_buffer = true;
        }
        break;
      }
      case EOF: {
        this->token.push_back(Token{"EOF", line, Type::kEOF});
        done = true;
        break;
      }
      default: {
        if(isdigit(ch)){
          Type type = Type::kIntLiteral;
          std::string number(1, ch);
          ch = GetNextChar();

          while(isdigit(ch)){
            number += ch;
            ch = GetNextChar();
          }
          if(ch=='.') {
            number += ch;
            ch = GetNextChar();
            if(not isdigit(ch)) return false;
            type = kRealLiteral;
            is_buffer = true;
            do {
              number += ch;
              ch = GetNextChar();
            } while(isdigit(ch));
          }
          this->token.push_back(Token{number, line, type});
          is_buffer = true;
        } else if (isalpha(ch)) {
          //TODO
        }
      }
    }
  }
}
