// https://acmp.ru/index.asp?main=source&id=8424402

#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include "assert.h"
 
using namespace std;
 
int main() {
  int n;
  int c[2000] = {0};
  c[0] = 1;
  freopen("input.txt", "r", stdin);
  cin >> n;
  int carry = 0, temp;
 
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < 2000; i++) {
      temp = c[i] * 2 + carry;
      carry = temp / 10;
      c[i] = temp % 10;
    }
  }
 
  for (int i = n - 1; i >= 0; i--) {
    if (c[i] != 0) {
      for (int j = i; j >= 0; j--) {
        cout << c[j];
      }
      break;
    }
  }
  return 0;
}
