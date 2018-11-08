// https://acmp.ru/index.asp?main=source&id=8510567

#include <iostream>
using namespace std;
 
long long n, k, a[56][56];
long long calc(int, int);
int main() {
  cin >> n;
  for (int i = 1; i <= 55; i++)
    for (int j = 1; j <= 55; j++) a[i][j] = -1;
  a[0][0] = 0, a[1][1] = 1, a[2][1] = 0, a[2][2] = 1;
 
  long long ans = 0;
  for (long long i = n; i >= 2; i--) ans += calc(n, i);
  if (n == 1) {
    cout << "1" << endl;
    return 0;
  }
  printf("%lld", ans);
 
  return 0;
}
 
long long calc(int nn, int kk) {
  if (nn <= 0 || kk <= 0) return a[nn][kk] = 0;
  if (a[nn][kk] != -1) return a[nn][kk];
 
  if (nn == kk) return a[nn][kk] = calc(nn - 1, nn - 1) + calc(nn - 1, nn - 2);
  if (nn > kk) return a[nn][kk] = calc(kk - 1, kk - 1);
  return a[nn][kk] = 0;
}
 
// 2 1 
// 3 2 
// 4 4 
// 5 6 
// 6 9 
// 7 14 
// 8 21 
// 9 31
