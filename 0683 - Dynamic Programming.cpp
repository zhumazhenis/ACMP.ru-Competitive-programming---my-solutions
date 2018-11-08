// https://acmp.ru/index.asp?main=source&id=9034326

/*
 
g++ a.cpp -o a && ./a
 
*/
 
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
 
using namespace std;
 
int a[109];
int n;
long long m[109][109];
 
int main() {
  // freopen("a.txt", "r", stdin);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
 
  // start
  for (int d = 2; d <= n - 1; d++) {
    for (int i = 1; i <= n - d; i++) {
      long long mi = INT32_MAX;
      for (int k = i + 1; k <= i + d - 1; k++) {
        mi = min(mi, m[i][k] + m[k][i + d] + a[k] * (a[i] + a[i + d]));
      }
      m[i][i + d] = mi;
    }
  }
 
  cout << m[1][n] << endl;
 
  return 0;
}
