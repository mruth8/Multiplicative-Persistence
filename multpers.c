#include "gmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void fact(){
  int i;
  mpz_t p;
  mpz_t cur;
  char numstr[] = "6788";
  int n = 4;
  int k = 0;
  mpz_set_str(cur, numstr, 10);
  do {
    mpz_init_set_ui(p,1); /* p = 1 */
    for (i=0; i < n ; ++i){
      mpz_mul_ui(p,p,(numstr[i]-'0')); /* p = p * num[i] */
    }
    ++k;
    printf ("%d - ", k);
    mpz_out_str(stdout,10,p);
    printf ("\n");

  } while (1 > 1);
  mpz_clear(p);
}

int main(int argc, char * argv[]){
  fact();
  return 1;
}
