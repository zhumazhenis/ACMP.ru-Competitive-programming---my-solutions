// https://acmp.ru/index.asp?main=source&id=8526117

#include <iostream>
#include <vector>
using namespace std;
 
char calc(int, int, int);
char d[201][201][101];
 
int main() {
  freopen("input.txt", "r", stdin);
  int n, m;
  cin >> n >> m;
 
  // start
  for (int i = 0; i <= 200; i++)
    for (int j = 0; j <= 200; j++)
      for (int k = 0; k <= 100; k++) d[i][j][k] = '0';
 
  d[0][0][0] = '2';
  d[0][0][1] = d[0][1][0] = d[1][0][0] = d[0][0][1] = '1';
  cout << calc(0, n, m);
 
  return 0;
}
 
char calc(int k, int n, int m) {
  if (d[k][n][m] != '0') return d[k][n][m];
  if (k > 0 && calc(k - 1, n, m) == '2') return d[k][n][m] = '1';
  if (n > 0 && calc(k + 1, n - 1, m) == '2') return d[k][n][m] = '1';
  if (n > 0 && calc(k, n - 1, m) == '2') return d[k][n][m] = '1';
  if (m > 0 && calc(k + 1, n, m - 1) == '2') return d[k][n][m] = '1';
  if (m > 0 && calc(k, n + 1, m - 1) == '2') return d[k][n][m] = '1';
  if (m > 0 && calc(k, n, m - 1) == '2') return d[k][n][m] = '1';
  return d[k][n][m] = '2';
}
