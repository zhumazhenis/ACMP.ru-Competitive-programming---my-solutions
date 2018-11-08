// https://acmp.ru/index.asp?main=source&id=9031895

/*
 
g++ a.cpp -o a && ./a
 
*/
 
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
 
using namespace std;
 
int m[109], k[109];
int n;
long long ans[109][109];
 
int toNorm(int k) {
  if (k > n) return k - n;
  if (k <= 0) return k + n;
}
 
int main() {
  // freopen("a.txt", "r", stdin);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> m[i] >> k[i];
  }
 
  // start
  for (int d = 1; d <= n - 1; d++) {
    for (int i = 1; i <= n - d; i++) {
      long long mi = INT64_MAX;
      for (int j = i; j <= i + d - 1; j++) {
        mi = min(mi, ans[i][j] + ans[j + 1][i + d] + k[i + d] * m[i]);
      }
      ans[i][i + d] = mi;
    }
  }
 
  cout << ans[1][n] << endl;
  return 0;
}
