// https://acmp.ru/index.asp?main=source&id=8536072

#include <algorithm>
#include <iostream>
 
/*
 
g++ a.cpp -o a && a
 
*/
 
using namespace std;
int a[1001], d[1001];
 
int main() {
  freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
 
  // start
  for (int i = 1; i <= n; ++i) {
    d[i] = 1;
    for (int j = 1; j <= i; ++j)
      if (a[j] < a[i]) d[i] = max(d[i], 1 + d[j]);
  }
 
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, d[i]);
 
  cout << ans;
 
  return 0;
}
