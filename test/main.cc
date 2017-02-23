#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "../include/lex/scanner.h"
int main(){
  FILE* f;
  f = fopen("lex1.pas", "r");
  Scanner *s = new Scanner();
  s->ReadToken(f);
  s->PrintToken();

  fclose(f);
}
