#include <iostream>
#include <stdio.h>
using namespace std;

//always set per equal to 0
void MultPersRecur(long num, int per) {
  int persistence = per;
  string s = to_string(num);
  if (persistence == 0) {
    cout << "Recur start = " << s << endl;
  } else {
    cout << "next num = " << s << endl;
  }
  if (s.length() == 1) {
    cout << "Persistence = " << persistence << endl;
    return;
  }
  long result = 1;
  for (int i = 0; i < s.length(); i++) {
    char dig = s.at(i);
    long nextDig = dig - 48;
    result *= nextDig;
  }
  persistence += 1;
  MultPersRecur(result, persistence);
}

int MultPersLoop(long num) {
  string s = to_string(num);
  int persistence = 0;
  cout << "Loop start = " << s << endl;
  while (s.length() > 1) {
    long result = 1;
    for (int i = 0; i < s.length(); i++) {
      char dig = s.at(i);
      long nextDig = dig - 48;
      result *= nextDig;
    }
    cout << "next num = " << result << endl;
    persistence += 1;
    s = to_string(result);
  }
  cout << "Persistence = " << persistence;
  return persistence;
}

void loopThroughHelper(int N, char digits[]) {
  int numElems = ((N+1)*(N+2))/2;
  char arr [numElems];
  int rowCounter = N - 2;
  int count = 1;
  for (int i = 0; i < N; i++) {
    arr[i] = digits[0];
  }
  printf("%s\n", arr);
  //printf("%d", mp(arr));
  for (int j = 0; j < 2; j++) {
    arr[N-1] = digits[j+1];
    printf("%s\n", arr);
    //printf("%d", mp(arr));
    count++;
  }
  while (count < numElems) {
    for (int k = N-1; k >= rowCounter; k--) {
      arr[k] = digits[1];
    }
    printf("%s\n", arr);
    //printf("%d", mp(arr));
    count++;
    for (int m = N-1; m >= rowCounter; m--) {
      arr[m] = digits[2];
      printf("%s\n", arr);
      //printf("%d", mp(arr));
      count++;
    }
    rowCounter--;
  }
}

void loopThrough(int N) {
  char digits237 [] = {'2','3','7'};
  char digits357 [] = {'3','5','7'};
  loopThroughHelper(N, digits237);
  printf("~~~~~~~~~~\n");
  loopThroughHelper(N, digits357);
}

int main () {
  //MultPersRecur(277777788888899, 0);
  //MultPersLoop(277777788888899);
  loopThrough(4);
}
