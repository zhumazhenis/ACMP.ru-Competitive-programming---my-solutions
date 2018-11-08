// https://acmp.ru/index.asp?main=source&id=8440926

#include <algorithm>
#include <iostream>
using namespace std;
 
int *money;
int n, k, *a;
int refund(int m);
 
int main() {
  freopen("input.txt", "r", stdin);
  cin >> n;
  a = new int[n];
 
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  cin >> k;
 
  money = new int[k + 1];
  for (int i = 0; i <= k; i++) {
    money[i] = 0;
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) money[a[i]] = 1;
  for (int i = 1; i <= k; i++) refund(i);
  cout << money[k];
}
 
int refund(int m) {
  int minimum = INT32_MAX, temp;
  bool check = false;
 
  if (m == 0) return 0;
  if (money[m] != 0) return money[m];
  for (int i = 0; i < n; i++)
    if (m >= a[i]) {
      temp = refund(m - a[i]);
      if (temp != -1 && temp != 0) {
        minimum = min(1 + temp, minimum);
        check = true;
      }
    }
  check ? money[m] = minimum : money[m] = -1;
  return money[m];
}
