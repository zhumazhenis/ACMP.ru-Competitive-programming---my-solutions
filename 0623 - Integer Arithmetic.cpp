// https://acmp.ru/index.asp?main=source&id=8424425

#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include "assert.h"
 
using namespace std;
 
int main() {
  int n, current = 0, next = 1, temp;
  freopen("input.txt", "r", stdin);
  cin >> n;
 
  for (int i = 0; i < n; i++) {
    temp = next;
    next = (current + next) % 10;
    current = temp % 10;
  }
  cout << next;
  return 0;
}
