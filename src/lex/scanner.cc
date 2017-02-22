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
Token token_buff;

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

void Scanner::PrintToken() {
  int len = token.size();

  for(int i = 0 ; i < len; ++i)
    printf("Token category: %s \t Lexeme: %s\n\t Line: %u", GetValueType(token.at(i).type),
          (token.at(i).lexeme).c_str(), token.at(i).line);
}

bool Scanner::ReadToken(FILE* stream) {
  bool done = true;

  while(not done){
    char ch = GetNextChar(stream);

    switch (ch) {
      case '+': case:'-' {
        token_buff.lexeme += ch;
        token_buff.line = line;
        token_buff.type = Type::kAddOperator;
        break;
      }
      case:'*' case:'/' {
        token_buff.lexeme += ch;
        token_buff.line = line;
        token_buff.type = Type::kMulOperator;
        break;
      }
      case EOF: {

        break;
      }

    }
  }
}

inline void SetTokenBuff(const )
