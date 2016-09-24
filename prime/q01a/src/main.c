#include <stdio.h>
#include <stdlib.h>
#include "libprimo.h"

int main(){
  unsigned int i = gera_primo();

  printf("%u\n", i);
  return 0;
}
