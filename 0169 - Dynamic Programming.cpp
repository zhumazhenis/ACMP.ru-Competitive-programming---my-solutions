// https://acmp.ru/index.asp?main=source&id=8510189

#include <iostream>
using namespace std;
 
long long n, k, a[38][38];
long long calc(int, int);
int main() {
  cin >> n >> k;
  for (int i = 1; i <= 37; i++)
    for (int j = 1; j <= 37; j++) a[i][j] = -1;
  a[1][1] = 1;
  cout << calc(n, k);
 
  return 0;
}
 
long long calc(int nn, int kk) {
  if (a[nn][kk] != -1) return a[nn][kk];
  if (nn > kk) return a[nn][kk] = 0;
  return a[nn][kk] = calc(nn - 1, kk - 1) + calc(nn + 1, kk - 1);
}
