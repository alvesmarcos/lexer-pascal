//============== types.h - Tipos de tokens ==============//
//
//               The pascc compiler
//
// Este arquivo possui todos os tipos de tokens especificados
// na linguagem pascal, e uma funcao que retorna o nome
// literal da constante.
//
//============== ------------------------- ==============//

#ifndef PASCC_LEX_TYPES
#define PASCC_LEX_TYPES

#include <map>

enum Type {
  kKeyword,
  kIdentifier,
  kIntLiteral,
  kRealLiteral,
  kDelimiter,
  kCommand,
  kRelOperator,
  kAddOperator,
  kMulOperator,
  kEOF
};
extern const std::map<Type, const char*> kGetStrType;

#endif //PASCC_LEX_TYPES
