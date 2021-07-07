#include "gmp.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int mp(char * orig){
	 char numstr[strlen(orig) + 1];
		//printf("strlenorig ~ %ld ~ ", strlen(orig));
  int i;
  mpz_t p;
  char digit;
  int hasZero;
  int pers = 0;
  size_t n = strlen(orig);
  int safety = 0;
		for (i = 0; i < n; i++) { //used so that the original char array is not changed
			 numstr[i] = orig[i];
		}
		numstr[n] = '\0';
  do {
    mpz_init_set_ui(p,1); /* p = 1 */
    hasZero = 0;
    n = strlen(numstr);
    for (i = 0; i < n ; ++i){
      mpz_mul_ui(p,p,(numstr[i]-'0')); /* p = p * num[i] */
						//mpz_out_str(stdout,10,p);
      //printf (" ~ multiplications i guess \n");
    }
    ++pers;
    //printf ("%d - ", pers);
    //mpz_out_str(stdout,10,p);
    //printf ("\n");
    mpz_get_str(numstr,10,p);
    if (++safety > 12) { //used when testing because the highest known multiplicative persistence is 11
      break;
    } 
  } while (strlen(numstr) > 1);
  mpz_clear(p);
  return pers; //returns the multiplicative persistence as an int
}

void numGeneratorHelper(int N, char digits[], int freq[]) {
  int numElems = ((N+1)*(N+2))/2; //number of elements that should be in the 
		int mpNum = 0; //multiplicative persistence
  char num [N + 1]; //char array
  int rowCounter = N - 2; //used in calculating the new arrays of numbers (222 -> 223 -> 227 -> 233...)
  int count = 1; 
  for (int i = 0; i < N; i++) { //creates the original array with 222...
    num[i] = digits[0];
  }
		num[N] = '\0'; //sets the last spot in the array to \0
  //printf("%s, ", num);
		mpNum = mp(num); //calls mp which returns the multiplicative persistence
  //printf("%d\n", mpNum);
		freq[mpNum]++; 
  for (int j = 0; j < 2; j++) { //creates the next part of the array 223...
    num[N-1] = digits[j+1]; 
				//printf("%s, ", num);
				mpNum = mp(num);
				//printf("%d\n", mpNum);
				freq[mpNum]++;
    count++;
  }
  while (count < numElems) { //finishes off the array 337 -> 377 -> 777
    for (int k = N-1; k >= rowCounter; k--) {
      num[k] = digits[1];
    }
    //printf("%s, ", num);
				mpNum = mp(num);
    //printf("%d\n", mpNum);
				freq[mpNum]++;
    count++;
    for (int m = N-1; m >= rowCounter; m--) {
      num[m] = digits[2];
      //printf("%s, ", num);
						mpNum = mp(num);
      //printf("%d\n", mpNum);
						freq[mpNum]++;
      count++;
    }
    rowCounter--;
  }
}
//numGenerator creates two char arrays with the two sets of ways to most likely get a number with a high multiplicative persistence: 2,3,7 or 3,5,7
void numGenerator(int N, int freq[]) {
  char digits237 [] = {'2','3','7'};
  char digits357 [] = {'3','5','7'};
  numGeneratorHelper(N, digits237, freq);
  printf("~~~~~~~~~~\n"); //break in between the two sets of numbers
  numGeneratorHelper(N, digits357, freq);
}
//allNums was used to test mp, currently not in use
void allNums(int numDigits) {
  char numstr[numDigits + 1];
  int rnd0,rnd1,rnd2;
  int remaining = 0;
  int nextRand = 0;
  int freq[12];
  int i, j, k;
  int p;
  for (i = 0; i < 12; ++i) {
    freq[i] = 0;
  }
  srand(69);
  for (j = 0; j < 100; ++j) {
    rnd0 = rand() % numDigits;
    rnd1 = rand() % (numDigits - rnd0);
    rnd2 = numDigits - rnd0 - rnd1;
    //printf ("rnd0 = %d, rnd1 = %d, rnd2 = %d\n",rnd0,rnd1,rnd2);
    k = 0;
    for (i = 0; i < rnd0; ++i) {
      numstr[k] = '2';
      ++k;
    }
    for (i = 0; i < rnd1; ++i) {
      numstr[k] = '3';
      ++k;
    }
    for (i = 0; i < rnd2; ++i) {
      numstr[k] = '7';
      ++k;
    }
    numstr[numDigits] = '\0';
  //printf ("multiplicative persistence of %s is \n", numstr);
  //printf ("%s ~ \n",numstr);
  p = mp(numstr);
  //printf ("pers = %d\n",p);
  ++freq[p];
}
  for (i = 0; i < 12; ++i) {
    printf ("frequency of %d is %.2f\n", i, freq[i] / 1.0);
  }
}

int main(int argc, char * argv[]){
		int N;
		int i, j, k;
		double percent;
		int numElems;
		int freq[13];
		for(k = 3; k < 200; k++) { //used to do the whole proccess for multiple digits in size
			N = k;
			numElems = ((N+1)*(N+2));
			printf("%d, %d", N, N);
			for (i = 0; i < 13; i++) { //used to set the frequency to 0 everytime
					freq[i] = 0;
			}
			numGenerator(N, freq);
			for (j = 0; j < 13; j++) { //used to show the percentage of each multiplicative persistence
				percent = 100.0*freq[j]/numElems;
				printf("%d, %.2f\n", j, percent);
			}
		}
  return 1;
}
