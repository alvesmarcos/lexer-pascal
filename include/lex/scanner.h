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

#include <stdlib.h>
#include <vector>
#include "../lex/type.h"

struct Token {
  std::string lexeme;
  Type type;
};

class Scanner {
  public:
    Scanner() = default;
    // Abre arquivo e classifica o simbolo encontrado.
    bool ReadToken(File* stream);
    // Captura o próximo char do arquivo.
    char GetNextChar();
  private:
    // Conjunto de tokens presente no arquivo.
    std::vector<Token> token;
};

#endif //PASCC_LEX_SCANNER
