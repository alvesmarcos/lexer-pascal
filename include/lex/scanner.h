//============== scanner.h - Leitura Token ==============//
//
//               The pascc compiler
//
// Este arquivo possui o formato do token (lexeme,
// type) e classe responsavel (Scanner) pela tokenizacao
// dos simbolos encontrados no arquivo *.pas.
//
//============== ------------------------- ==============//

#ifndef PASCC_LEX_SCANNER
#define PASCC_LEX_SCANNER

#include <stdio.h>
#include <vector>
#include <string>
#include "../lex/types.h"

struct Token {
  std::string lexeme;
  unsigned int line;
  Type type;

  Token(std::string lex, unsigned int lin, Type tp):
  lexeme(lex), line(lin), type(tp){}
};

class Scanner {
  public:
    Scanner(FILE* file);
    ~Scanner();
    // Imprime uma mensagem de erro + string
    void LexerError(std::string e) const;
    // Imprime todos os tokens do vector
    void PrintToken() const;
    // Abre arquivo e classifica o simbolo encontrado
    bool BuildToken();
  private:
    char GetNextChar();
    FILE *stream;
    // Conjunto de tokens presente no arquivo
    std::vector<Token> token;
};

#endif //PASCC_LEX_SCANNER
