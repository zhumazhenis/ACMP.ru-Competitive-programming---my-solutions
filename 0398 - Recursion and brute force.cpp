// https://acmp.ru/index.asp?main=source&id=8532652

#include <algorithm>
#include <iostream>
 
/*
 
g++ a.cpp -o a && a
 
*/
 
using namespace std;
int d[1501][5];
int calc(int n, int k);
 
int main() {
  freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
 
  for (int i = 0; i <= 1500; i++)
    for (int j = 0; j <= 4; j++) d[i][j] = -1;
 
  // start
  cout << calc(n, 4);
  return 0;
}
 
int calc(int n, int k) {
  if (d[n][k] != -1) return d[n][k];
  if (n < 0 || k < 1) return 0;
  if (n == k) return d[n][k] = 1;
  if (n < k) return d[n][k] = 0;
  return d[n][k] = calc(n - 1, k - 1) + calc(n - k, k);
}
