#include "libprimo.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define NOT_PRIME 10
#define PRIME 0

int teste(int primo){
    double raiz_n;
    raiz_n = ceil(sqrt(primo));
    (int) raiz_n;
    if (primo%2 == 0) return 1;

    for (int i = 3; i <= raiz_n; i = i + 2){
	if ((primo % i) == 0)
	    return 1;
    }
    return 0;
}
int gera_primo(){

  int num = NOT_PRIME;
  srand(time(NULL));
  while (teste(num)){
    num = rand();
  }
  return num;
}
