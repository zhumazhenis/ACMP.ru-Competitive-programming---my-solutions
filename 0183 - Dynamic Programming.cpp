// https://acmp.ru/index.asp?main=source&id=8434673

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int n, p, d[1000001];
void calc (int);
 
int main() {  
  freopen("input.txt", "r", stdin);  
  cin >> n >> p;
  for (int i = 1; i <= n; i++) d[i] = -1;
  d[0] = 0, d[1] = 0, d[2] = 1;
  calc(n);
  cout << d[n] % p;
  return 0;
}
 
void calc(int k) {
  for (int i = 3; i <= k; i++) {
    if(i % 2)
      d[i] = d[i - 1] % p;
    else
      d[i] = (d[i - 1] + d[i / 2]) % p;
  }
}
