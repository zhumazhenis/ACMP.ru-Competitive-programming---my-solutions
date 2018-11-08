// https://acmp.ru/index.asp?main=source&id=8487225

#include <iostream>
using namespace std;
 
long long d[51];
 
int main() {
  int m, n;
  cin >> m >> n;  
  for(int i = 0; i < m; i++) d[i] = 1;  
  for(int i = m; i <= n; i++) 
    d[i] = d[i - 1] + d[i - m];  
  cout << d[n];
  return 0;
}
