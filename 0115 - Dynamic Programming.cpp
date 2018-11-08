// https://acmp.ru/index.asp?main=source&id=8517831

#include <iostream>
#include <vector>
using namespace std;
 
int a[101][101], s[101][101];
int calc(int, int);
 
int main() {
  // freopen("in", "r", stdin);
  int n, m, ma = INT32_MIN;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      s[i][j] = -1;
    }
 
  // start
  s[1][1] = a[1][1];
  calc(n, m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int p = i; p <= n; p++)
        for (int q = j; q <= m; q++)
          ma = max(s[p][q] - s[p][j - 1] - s[i - 1][q] + s[i - 1][j - 1], ma);
 
  cout << ma;
  return 0;
}
 
int calc(int n, int m) {
  if (n <= 0 || m <= 0) return 0;
  if (s[n][m] != -1) return s[n][m];
  s[n][m] = calc(n, m - 1) + calc(n - 1, m) - calc(n - 1, m - 1) + a[n][m];
  return s[n][m];
}
