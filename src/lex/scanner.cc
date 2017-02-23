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

inline char GetNextChar(FILE* stream) {
  if(valid)
    return buffer;
  else
    return getc(stream);
}

void Scanner::PrintToken() const {
  int len = token.size();

  for(int i = 0 ; i < len; ++i){
    printf("Token category: %s \t Lexeme: %s\t Line: %d\n", kGetStrType.at(token.at(i).type),
          (token.at(i).lexeme).c_str(), token.at(i).line);
  }
}

bool Scanner::ReadToken(FILE* stream) {
  bool done = false;

  while(not done){
    char ch = GetNextChar(stream);

    switch (ch) {
      case '+': case '-': {
        token.push_back(Token{std::string(1, ch), line, Type::kAddOperator});
        break;
      }
      case '*': case '/': {
        token.push_back(Token{std::string(1, ch), line, Type::kMulOperator});
        break;
      }
      case EOF: {
        token.push_back(Token{"EOF", line, Type::kEOF});
        break;
      }
    }
    done = true;
  }
}
