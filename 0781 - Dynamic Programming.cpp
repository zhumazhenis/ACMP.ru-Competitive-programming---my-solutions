// https://acmp.ru/index.asp?main=source&id=8684159

#include <iostream>
 
using namespace std;
 
// long long calc(int);
/*
 
g++ a.cpp -o a && ./a
 
*/
long long d[31];
 
int main() {
  freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
 
  // start
  d[1] = 2, d[2] = 4, d[3] = 6;
  for (int i = 4; i <= n; i++) {
    d[i] = 2 * d[i - 1] - d[i - 3];
  }
 
  cout << d[n] << endl;
  return 0;
}
