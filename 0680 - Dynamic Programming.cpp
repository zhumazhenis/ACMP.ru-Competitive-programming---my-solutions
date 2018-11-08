// https://acmp.ru/index.asp?main=source&id=8424606

#include <cmath>
#include <iostream>
 
using namespace std;
 
int main() {
  long long n;
  freopen("input.txt", "r", stdin);
  cin >> n;
  printf("%lld", 3 * (long long)floor(pow(2, n - 1)));
  return 0;
}
