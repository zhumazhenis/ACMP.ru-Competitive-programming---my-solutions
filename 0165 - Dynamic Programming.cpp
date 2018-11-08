// https://acmp.ru/index.asp?main=source&id=8425781

#include <cmath>
#include <iostream>
#include "stdio.h"
 
using namespace std;
int calc(int, int);
int field[80][80];
int table[80][80];
int ans = 0, n, m;
 
int main() {
  freopen("input.txt", "r", stdin);
  cin >> n >> m;
 
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> field[i][j];
 
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) table[i][j] = -1;
 
  table[1 + field[1][1]][1] = table[1][1 + field[1][1]] = 1;
  table[1][1] = 0;
 
  cout << calc(n, m);
  return 0;
}
 
int calc(int i, int j) {
  if (i < 1 || j < 1 || i > n || j > m) return 0;
  if (table[i][j] != -1) {
    return table[i][j];
  } else {
    table[i][j] = 0;
    for (int k = i - 1; k >= 1; k--) {
      if (field[k][j] == i - k) table[i][j] += calc(k, j);
    }
 
    for (int k = j - 1; k >= 1; k--) {
      if (field[i][k] == j - k) table[i][j] += calc(i, k);
    }
 
    return table[i][j];
  }
}
