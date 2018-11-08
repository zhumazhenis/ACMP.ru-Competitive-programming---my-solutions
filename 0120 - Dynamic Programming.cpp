// https://acmp.ru/index.asp?main=source&id=8424636

#include <cmath>
#include <iostream>
#include "stdio.h"
 
using namespace std;
int calc(int, int);
int field[23][23];
int table[23][23];
 
int main() {
  int n, m;
  freopen("input.txt", "r", stdin);
  cin >> n >> m;
 
  for (int i = 1; i <= 23; i++)
    for (int j = 1; j <= 23; j++) table[i][j] = -1;
 
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", field[i] + j);
 
  table[1][1] = field[1][1];
  cout << calc(n, m);
 
  return 0;
}
 
int calc(int n, int m) {
  if (n < 1 || m < 1) return INT32_MAX;
  if (table[n][m] != -1) {
    return table[n][m];
  } else {
    table[n][m] = min(calc(n - 1, m), calc(n, m - 1)) + field[n][m];
    return table[n][m];
  }
}
