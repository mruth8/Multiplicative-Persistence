#include <iostream>
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

int main () {
  MultPersRecur(277777788888899, 0);
  MultPersLoop(277777788888899);
}