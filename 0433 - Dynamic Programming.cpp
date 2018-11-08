// https://acmp.ru/index.asp?main=source&id=8529234

#include <algorithm>
#include <iostream>
 
using namespace std;
long long d[2000009], dcnt[2000009], a[1000009];
 
int main() {
  freopen("input.txt", "r", stdin);
  int n;
  string s;
  cin >> n >> s;
  s = " " + s;
 
  // start
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'a')  // delta = a - b
      d[i] = d[i - 1] + 1;
    else
      d[i] = d[i - 1] - 1;
    // cout << d[i] << " ";
  }
 
  for (int i = 1; i <= n; i++) {
    dcnt[n + d[i]]++;
    a[i] = a[i - 1] + dcnt[n + d[i]] - 1;
    if (d[i] == 0) a[i]++;
  }
 
  cout << a[n];
  return 0;
}
