// https://acmp.ru/index.asp?main=source&id=8520477

#include <iostream>
#include <vector>
using namespace std;
 
long long calc(int, int);
int a[101];
 
int main() {
  freopen("input.txt", "r", stdin);
  int n, k, temp = 0, high = 0, low = INT32_MIN, count = 0, m;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    low = max(a[i], low);
    high += a[i];
  }
  cin >> k;
 
  // start
 
  while (low != high) {
    count = 0, temp = a[1];
    m = (low + high) / 2;
 
    for (int i = 2; i <= n; i++) {
      if (temp + a[i] <= m) {
        temp += a[i];
        count++;
      } else {
        temp = a[i];
      }
    }
 
    if (n - count > k) {
      low = m + 1;
    } else {
      high = m;
    }
  }
  cout << low;
 
  return 0;
}
