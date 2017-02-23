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
bool valid = false;

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
  if(valid){
    valid = false;
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

    switch (ch) {
      case '{': {
        while(ch!='}'){
          ch = GetNextChar();
          if(ch==EOF){
            valid = true;
            fprintf(stderr, "ERROR: Comentário esperado!\n");
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
          valid = true;
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
          valid = true;
        }
        break;
      }
      case '\n':{
        ++line;
        break;
      }
      case EOF: {
        this->token.push_back(Token{"EOF", line, Type::kEOF});
        done = true;
        break;
      }
      default: {
      }
    }
  }
}
