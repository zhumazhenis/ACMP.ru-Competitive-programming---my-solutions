// https://acmp.ru/index.asp?main=source&id=8432389

#include <iostream>
using namespace std;
 
int main() {
  long long s[80], n;
  cin >> n;
  s[1] = 1, s[2] = 2, s[3] = 4;
  for (int i = 4; i <= n; i++) s[i] = s[i - 1] + s[i - 2] + s[i - 3];
  cout << s[n];
  return 0;
}
