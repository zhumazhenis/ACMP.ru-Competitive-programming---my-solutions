// https://acmp.ru/index.asp?main=source&id=8434237

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int n;
int a[5001], b[5001], c[5001], d[5001];
 
int min(int a, int b, int c) {
  return (int)min(min(a, b), c);
}
 
int min(int a, int b, int c, int d) {
  return (int)min(min(a, b, c), d);
}
 
int calc (int);
 
int main() {  
  freopen("input.txt", "r", stdin);  
  cin >> n;  
  for(int i = 1; i <= n; i++) scanf("%d%d%d", a + i, b + i, c + i);  
 
  for (int i = 1; i <= n; i++) d[i] = -1;
  d[1] = a[1];
  d[2] = min(a[1] + a[2], b[1]);
  d[3] = min(c[1], b[1] + a[3], a[1] + b[2], a[1] + a[2] + a[3]);
  cout << calc(n);
  return 0;
}
 
int calc(int k) {
  if (d[k] != -1) {
    return d[k];
  } else {
    int s_5 = calc(k - 1) + a[k];
    int s4_5 = min(calc(k - 2) + b[k - 1], calc(k - 2) + a[k - 1] + a[k]);
    int temp = calc(k - 3);
    int s3_5 = min(temp + c[k - 2], temp + b[k - 2] + a[k], temp + a[k - 2] + min(b[k - 1], a[k - 1] + a[k]));
 
    d[k] = min(s_5, s4_5, s3_5);
  }
  return d[k];
}
