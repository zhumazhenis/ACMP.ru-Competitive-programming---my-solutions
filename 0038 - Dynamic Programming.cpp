// https://acmp.ru/index.asp?main=source&id=8523877

#include <iostream>
#include <vector>
using namespace std;
 
int calc(int, int);
int addr[101][101], s[101][101], a[101];
 
int main() {
  freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
 
  // start
  for (int d = 0; d <= n - 1; d++) {
    for (int l = 1; l <= n - d; l++) {
      int r = l + d, sum1, addr1, sum0, addr0;
      if (l == r) {
        s[l][r] = a[l];
        addr[l][r] = 0;
        continue;
      }
      // r
      int temp = addr[l][r - 1];
      if (temp == 0) {
        sum1 = a[r] + s[l + 1][r - 1];
        addr1 = 1;
      } else {
        sum1 = a[r] + s[l][r - 2];
        addr1 = 1;
      }
 
      // l
      temp = addr[l + 1][r];
      if (temp == 0) {
        sum0 = a[l] + s[l + 2][r];
        addr0 = 0;
      } else {
        sum0 = a[l] + s[l + 1][r - 1];
        addr0 = 0;
      }
 
      if (sum1 >= sum0) {
        s[l][r] = sum1;
        addr[l][r] = addr1;
      } else {
        s[l][r] = sum0;
        addr[l][r] = addr0;
      }
    }
  }
  int x = addr[1][n];
  if (x == 0) {
    if (s[1][n] - s[2][n] > 0)
      cout << "1";
    else if (s[1][n] - s[2][n] < 0)
      cout << "2";
    else
      cout << "0";
  } else {
    if (s[1][n] - s[1][n - 1] > 0)
      cout << "1";
    else if (s[1][n] - s[1][n - 1] < 0)
      cout << "2";
    else
      cout << "0";
  }
  return 0;
}
