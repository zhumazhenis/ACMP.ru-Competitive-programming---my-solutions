// https://acmp.ru/index.asp?main=source&id=8491276

#include <iostream>
using namespace std;
 
int d[11];
int main() {
  long long n, k;
  cin >> n >> k;
 
  d[1] = k - 1, d[2] = (k - 1) * k;
  for (int i = 3; i <= n; i++) {
    d[i] = (k - 1) * (d[i - 1] + d[i - 2]);
  }
  cout << d[n];
  return 0;
}
