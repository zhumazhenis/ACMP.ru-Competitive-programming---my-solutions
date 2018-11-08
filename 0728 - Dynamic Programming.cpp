// https://acmp.ru/index.asp?main=source&id=9051183

/*
 
g++ a.cpp -o a && ./a
 
*/
 
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
 
using namespace std;
 
int a[109], b[109], m;
long long d[10009];
char check[10009];
 
long long calc(int);
 
int main() {
  // freopen("a.txt", "r", stdin);
  int n;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i];
  }
 
  // start
  cout << calc(n) << endl;
 
  return 0;
}
 
long long calc(int n) {
  if (n <= 0) return 0;
  if (check[n]) {
    return d[n];
  }
  check[n] = true;
 
  long long ans = INT64_MAX;
  for (int i = 1; i <= m; i++) {
    ans = min(ans, calc(n - a[i]) + b[i]);
  }
  return d[n] = ans;
}
