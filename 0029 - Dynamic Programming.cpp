// https://acmp.ru/index.asp?main=source&id=8535933

#include <algorithm>
#include <iostream>
 
/*
 
g++ a.cpp -o a && a
 
*/
 
using namespace std;
long long d[30001], a[30001];
char flag[30001];
long long calc(int);
 
int main() {
  freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%lld", a + i);
 
  // start
  flag[0] = flag[1] = flag[2] = true;
  d[2] = abs(a[2] - a[1]);
  cout << calc(n);
  return 0;
}
 
long long calc(int n) {
  if (flag[n]) return d[n];
  flag[n] = true;
 
  d[n] = min(calc(n - 1) + abs(a[n] - a[n - 1]),
             calc(n - 2) + 3 * abs(a[n] - a[n - 2]));
  return d[n];
}
