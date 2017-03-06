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

namespace kw {
  extern const std::string kProgram;
  extern const std::string kVar;
  extern const std::string kInteger;
  extern const std::string kReal;
  extern const std::string kBoolean;
  extern const std::string kProcedure;
  extern const std::string kBegin;
  extern const std::string kEnd;
  extern const std::string kIf;
  extern const std::string kThen;
  extern const std::string kElse;
  extern const std::string kWhile;
  extern const std::string kDo;
  extern const std::string kNot;
}

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
