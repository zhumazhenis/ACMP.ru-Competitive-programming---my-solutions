// https://acmp.ru/index.asp?main=source&id=8517863

#include <iostream>
#include <vector>
using namespace std;
 
int d[100009], k;
int calc(int);
string s;
 
int main() {
  // freopen("in", "r", stdin);
  int n;
  cin >> n >> k >> s;
  for (int i = 1; i <= n; i++) d[i] = -1;
 
  // start
  s = " " + s;
  d[1] = 0;
  cout << calc(n);
 
  return 0;
}
 
int calc(int n) {
  if (n == 0) return 0;
  if (d[n] != - 1) return d[n];
  d[n] = INT32_MAX;
  for (int i = n - 1; i >= n - k && i >= 1; i--) {
    if (s[i] == s[n]) return d[n] = calc(i);
  }
 
  for (int i = n - 1; i >= n - k && i >= 1; i--) {
    d[n] = min(calc(i) + 1, d[n]);
  }
  return d[n];
}
