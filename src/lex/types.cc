//============== scanner.cc - Implementacao ==============//
//
//               The pascc compiler
//
// Implementacao do arquivo /include/types.h
//
//============== -------------------------- ==============//

#include "../../include/lex/types.h"

namespace kw {
  const std::string kProgram{"program"};
  const std::string kVar{"var"};
  const std::string kInteger{"integer"};
  const std::string kReal{"real"};
  const std::string kBoolean{"boolean"};
  const std::string kProcedure{"procedure"};
  const std::string kBegin{"begin"};
  const std::string kEnd{"end"};
  const std::string kIf{"if"};
  const std::string kThen{"then"};
  const std::string kElse{"else"};
  const std::string kWhile{"while"};
  const std::string kDo{"do"};
  const std::string kNot{"not"};
}

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
