//============== scanner.cc - Implementacao ==============//
//
//               The pascc compiler
//
// Implementacao do arquivo /include/types.h
//
//============== -------------------------- ==============//

#include "../../include/lex/types.h"

const std::map<Type, const char*> kGetStrType {
                                  {Type::kKeyword, "Keyword"},
                                  {Type::kIdentifier, "Identifier"},
                                  {Type::kIntLiteral, "Integer literal"},
                                  {Type::kRealLiteral, "Real literal"},
                                  {Type::kDelimiter, "Delimiter"},
                                  {Type::kCommand, "Command"},
                                  {Type::kRelOperator, "Relational operator"},
                                  {Type::kAddOperator, "Additive operator"},
                                  {Type::kMulOperator, "Multiplicative operator"},
                                  {Type::kEOF, "EOF"}};
