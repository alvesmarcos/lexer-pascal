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
extern const std::map<Type, const char*> kGetStrType;

#endif //PASCC_LEX_TYPES
