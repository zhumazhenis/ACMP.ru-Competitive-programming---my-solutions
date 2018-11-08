// https://acmp.ru/index.asp?main=source&id=8542937

#include <algorithm>
#include <iostream>
 
/*
 
g++ a.cpp -o a && a
g++ -O2 -Wl,--stack=67108864 -x c++ -std=c++11 a.cpp
 
*/
using namespace std;
int a[40];
 
int main() {
  freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
 
  // start
  a[0] = 1, a[2] = 3;
  for (int i = 4; i <= n; i += 2) a[i] = 4 * a[i - 2] - a[i - 4];
 
  cout << a[n];
  return 0;
}
