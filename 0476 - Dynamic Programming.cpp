// https://acmp.ru/index.asp?main=source&id=8526862

#include <iostream>
#include <set>
#include <vector>
using namespace std;
 
char d[251][251];
char calc(int, int);
 
int main() {
  freopen("input.txt", "r", stdin);
  int m, n;
  cin >> m >> n;
 
  // start
  for (int i = 1; i <= 250; i++)
    for (int j = 1; j <= 250; j++) d[i][j] = '0';
  d[1][1] = '2';
  cout << calc(m, n);
  return 0;
}
 
char calc(int m, int n) {
  if (d[m][n] != '0') return d[m][n];
  if (m == 1 || n == 1) return d[m][n] = '1';
  for (int i = n - 1; i >= 1; i--)
    if (calc(m, i) == '2') {
      return d[m][n] = '1';
    }
 
  for (int i = m - 1; i >= 1; i--)
    if (calc(i, n) == '2') {
      return d[m][n] = '1';
    }
 
  for (int i = m - 1, j = n - 1; i >= 1 && j >= 1; i--, j--)
    if (calc(i, j) == '2') {
      return d[m][n] = '1';
    }
  return d[m][n] = '2';
}
