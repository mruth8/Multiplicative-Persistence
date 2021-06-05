#include "gmp.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int mp(char * numstr){
  int i;
  mpz_t p;
  char digit;
  int hasZero;
  int pers = 0;
  size_t n = strlen(numstr);
  do {
    mpz_init_set_ui(p,1); /* p = 1 */
    hasZero = 0;
    n = strlen(numstr);
    for (i=0; i < n ; ++i){
      mpz_mul_ui(p,p,(numstr[i]-'0')); /* p = p * num[i] */
    }
    ++pers;
    printf ("%d - ", pers);
    mpz_out_str(stdout,10,p);
    printf ("\n");
    mpz_get_str(numstr,10,p);
  } while (mpz_sizeinbase(p,10) > 1);
  mpz_clear(p);
  return pers;
}

int main(int argc, char * argv[]){
  char str1[100];
  str1[0] = '6';
  str1[1] = '7';
  str1[2] = '8';
  str1[3] = '8';
  str1[4] = '\0';
  printf ("multiplicative persistence of %s is \n", str1);
  mp(str1);
  return 1;
}
