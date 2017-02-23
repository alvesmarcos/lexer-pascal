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
                                  {Type::kIntLiteral, "Int literal"},
                                  {Type::kRealLiteral, "Real literal"},
                                  {Type::kDelimiter, "Delimiter"},
                                  {Type::kCommand, "Command"},
                                  {Type::kRelOperator, "Rel operator"},
                                  {Type::kAddOperator, "Add operator"},
                                  {Type::kMulOperator, "Mult operator"},
                                  {Type::kEOF, "EOF"}};
