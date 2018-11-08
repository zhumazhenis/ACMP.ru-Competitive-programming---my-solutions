// https://acmp.ru/index.asp?main=source&id=8445503

#include <algorithm>
#include <iostream>
using namespace std;
 
/*
g++ b.cpp -o b && b
*/
int n, *a, *d;
int calc(int);
 
int main() {
  // read
  freopen("input.txt", "r", stdin);
  cin >> n;
  a = new int[n + 1];
  d = new int[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    d[i] = -1;
  }
 
  // start
  sort(a + 1, a + n + 1);
  d[2] = a[2] - a[1], d[1] = INT32_MAX;
  cout << calc(n);
  return 0;
}
 
int calc(int k) {
  if (d[k] != -1) return d[k];
  return d[k] = min(calc(k - 1), calc(k - 2)) + a[k] - a[k - 1];
}
