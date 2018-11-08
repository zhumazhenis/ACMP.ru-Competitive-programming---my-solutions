// https://acmp.ru/index.asp?main=source&id=8490955

#include <iostream>
#include <cmath>
using namespace std;
 
int d[1001];
int main() {
  int n;
  cin >> n;
 
  d[1] = 1;
  for (int i = 2; i <= n; i++)
    if (i % 2) 
      d[i] = d[i - 1];      
    else
      d[i] = d[i / 2] + d[i - 1];
       
  cout << d[n];
  return 0;
}
