// MIT License
//
// Copyright (c) 2017 Marcos Henrique Alves da Silva
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


#ifndef PASCC_LEX_SCANNER
#define PASCC_LEX_SCANNER

#include <stdio.h>
#include <queue>
#include <string>
#include "../lex/types.h"

struct Token {
  std::string lexeme;
  unsigned int line;
  Type type;

  Token() = default;
  Token(std::string lex, unsigned int lin, Type tp): lexeme(lex), line(lin), type(tp){}
};

class Scanner {
  public:
    Scanner(FILE* file);
    ~Scanner();
    // Imprime uma mensagem de erro + string
    void LexerError(std::string e) const;
    // Imprime todos os tokens do vector
    void PrintToken();
    // Abre arquivo e classifica o simbolo encontrado
    bool BuildToken();
    // Retorna um token
    Token GetNextToken();
  private:
    char GetNextChar();
    FILE *stream;
    // Conjunto de tokens presente no arquivo
    std::queue<Token> queue_token;
};

#endif //PASCC_LEX_SCANNER
