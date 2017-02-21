// Autor: Marcos Alves
// Data: 21 Fev 2017
//
// module: type.h
// Este arquivo contem todos os tipos possiveis, da linguagem pascal, para a
// classificacao do token. Existe tambem uma funcao cujo objetivo e retornar
// uma string com nome literal da constante passada por parametro.

#ifndef PASCC_LEX_TYPES
#define PASCC_LEX_TYPES

enum Type {
  kKeyword,
  kIdentifier,
  kIntLiteral,
  kRealLiteral,
  kDelimiter,
  kCommand,
  kRelOperator,
  kAddOperator,
  kMulOperator
};

inline const char* GetValueType(Type tp){
  switch (tp) {
    case kKeyword:
      return "Keyword";
    case kIdentifier:
      return "Identifier";
    case kIntLiteral:
      return "Integer literal";
    case kRealLiteral:
      return "Real literal";
    case kDelimiter:
      return "Delimiter";
    case kCommand:
      return "Command";
    case kRelOperator:
      return "Relational operator";
    case kAddOperator:
      return "Additive operator";
    case kMulOperator:
      return "Multiplicative operator";
  }
}

#endif //PASCC_LEX_TYPES
