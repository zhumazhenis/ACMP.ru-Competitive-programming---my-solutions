// https://acmp.ru/index.asp?main=source&id=8523853

#include <iostream>
#include <vector>
using namespace std;
 
int calc(int, int);
int d[31][31], n;
string s;
 
int main() {
  freopen("input.txt", "r", stdin);
  cin >> s;
 
  // start
  s = " " + s;
  n = s.length() - 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) d[i][j] = -1;
 
  cout << calc(1, n);
  return 0;
}
 
int calc(int l, int r) {
  if (l > r) return 0;
  if (l == r) return 1;
  if (d[l][r] != -1) return d[l][r];
  int i, ans = calc(l, r - 1);
  for (i = l; i <= r; i++)
    if (s[i] == s[r]) {
      if (i + 1 == r || i == r)
        ans++;
      else
        ans += calc(i + 1, r - 1) + 1;
    }
 
  return d[l][r] = ans;
}
