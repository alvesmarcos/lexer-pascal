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

// inline const char* GetValueType(Type t) {
//   switch (t) {
//     case kKeyword:
//       return "Keyword";
//     case kIdentifier:
//       return "Identifier";
//     case kIntLiteral:
//       return "Integer literal";
//     case kRealLiteral:
//       return "Real literal";
//     case kDelimiter:
//       return "Delimiter";
//     case kCommand:
//       return "Command";
//     case kRelOperator:
//       return "Relational operator";
//     case kAddOperator:
//       return "Additive operator";
//     case kMulOperator:
//       return "Multiplicative operator";
//     case kEOF:
//       return "EOF";
//     default:
//       return nullptr;
//   }
// }

#endif //PASCC_LEX_TYPES
