// https://acmp.ru/index.asp?main=source&id=8424293

#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include "assert.h"
 
using namespace std;
 
int dfs(int);
 
vector<vector<int>> g(44444);
char used[44444] = {false};
char field[222][222];
 
int main() {
  int n, m;
 
  freopen("input.txt", "r", stdin);
  cin >> n >> m;
 
  for (int i = 1; i <= n; i++) {
    scanf("%s", &field[i][1]);
  }
 
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (field[i][j] == '#') {
        if (field[i][j - 1] == '#' && j != 1)
          g[(i - 1) * m + j].push_back((i - 1) * m + j - 1);
        if (field[i][j + 1] == '#' && j != m)
          g[(i - 1) * m + j].push_back((i - 1) * m + j + 1);
        if (field[i - 1][j] == '#' && i != 1)
          g[(i - 1) * m + j].push_back((i - 2) * m + j);
        if (field[i + 1][j] == '#' && i != n)
          g[(i - 1) * m + j].push_back(i * m + j);
      }
    }
  }
 
  int ans = 0;
 
  for (int i = 1; i <= n * m; i++) {
    if (!used[i] && field[i / m + !!(i % m)][i % m + (!(i % m)) * m] == '#') {
      ans += dfs(i);
    }
  }
 
  cout << ans;
  return 0;
}
 
int dfs(int s) {
  used[s] = true;
  for (vector<int>::iterator i = g[s].begin(); i != g[s].end(); i++) {
    if (!used[*i]) dfs(*i);
  }
  return 1;
}
