// https://acmp.ru/index.asp?main=source&id=8532523

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
 
using namespace std;
int calc(int, int);
int d[101][101];
 
int main() {
  freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) d[i][j] = -1;
 
  // start
  int ans = 0;
  for (int i = n; i >= 0; i--) ans += calc(n, i);
  cout << ans;
  return 0;
}
 
int calc(int n, int k) {
  if (d[n][k] != -1) return d[n][k];
  int x = (int)ceil((sqrt(8 * n + 1) - 1) / 2);
  if (n <= 0 || k <= 0 || k < x || k > n) return d[n][k] = 0;
  if (n == k) return d[n][k] = 1;
  d[n][k] = 0;
  x = (int)ceil((sqrt(8 * (n - k) + 1) - 1) / 2);
  for (int i = k - 1; i >= 0; i--) {
    d[n][k] += calc(n - k, i);
  }
  return d[n][k];
}
