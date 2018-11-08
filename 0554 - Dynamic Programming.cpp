// https://acmp.ru/index.asp?main=source&id=8424597

#include <iostream>
 
using namespace std;
 
int main() {
  int n;
  freopen("input.txt", "r", stdin);
  cin >> n;
  cout << n * (n + 1) / 2 + 1;
  return 0;
}
