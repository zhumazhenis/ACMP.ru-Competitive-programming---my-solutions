// https://acmp.ru/index.asp?main=source&id=8578922

#include <algorithm>
#include <iostream>
 
/*
 
g++ a.cpp -o a && a
 
*/
 
using namespace std;
int d[1000009];
 
int min(int a, int b, int c) { return min(a, min(b, c)); }
 
int main() {
  freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
 
  // start
  for (int i = 2; i <= n; i++) {
    int a, b, c;
    a = b = c = INT32_MAX;
    if (i % 3 == 0) a = d[i / 3] + 1;
    if (i % 2 == 0) b = d[i / 2] + 1;
    c = d[i - 1] + 1;
    d[i] = min(a, b, c);
  }
 
  cout << d[n];
  return 0;
}
