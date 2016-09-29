#include "libprimo.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#define NOT_PRIME 10
#define PRIME 0

int gera_primo(){

  unsigned int num = NOT_PRIME;
  srand(time(NULL));
  while (testa_primo(num) != PRIME){
    num = rand() % UINT_MAX;
  }
  return num;
}

int testa_primo(int primo){
  int teste(int primo){
    double raiz_n;
    raiz_n = ceil(sqrt(primo));
    (int) raiz_n;
    for (int i = 3; i <= raiz_n; i = i + 2){
      if ((primo % i) == 0)
        return 1;
    }
    return 0;
  }
  if (primo != 2 && (primo % 2) == 0)
    return 1;
  else if (primo != 3 && (primo % 3) == 0)
    return 1;
  else if (primo != 5 && (primo % 5) == 0)
    return 1;
  else if (primo != 7 && (primo % 7) == 0)
    return 1;
  else if(teste(primo) != 0)
    return 1;
  else
    return 0;
}
