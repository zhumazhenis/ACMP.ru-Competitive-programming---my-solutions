// https://acmp.ru/index.asp?main=source&id=8447817

#include <iostream>
#include <algorithm>
using namespace std;
 
int n, d[1001];
char a[1001][1001];
int calc(int);
 
int main() {  
  // read
  freopen("input.txt", "r", stdin);
  cin >> n;  
  for(int i = 1; i <= n; i++) {
    char temp[n + 1];
    scanf("%s", temp + 1);
    for (int j = 1; j <= n; j++) {
      a[i][j] = temp[j];
    }
    d[i] = -1;
  } 
 
  // for(int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++) 
  //     cout << a[i][j];
  //   cout << endl;
  // }
  if (a[1][1] == '1')
    d[1] = 1;
  else 
    d[1] = 0;
  int ans = calc(n);
  cout << ans * ans;
 
  return 0;
}
 
int calc(int k) {
  if (d[k] != -1) return d[k];
  int temp = calc(k - 1) + 1;
  bool check = false;
 
  int count = 0;
  for (int i = 1; i <= k; i++) {
    bool check2 = true;
    for (int j = k - temp + 1; j <= k; j++) {
      if (a[i][j] == '0') {
        count = 0;
        check2 = false;
        break;
      }
    }
    if (check2)
      count++;
    if (count == temp) {
      check = true;
      break;
    }
  }
 
  count = 0;
  for (int j = 1; j <= k; j++) {
    bool check2 = true;
    for (int i = k - temp + 1; i <= k; i++) {
      if (a[i][j] == '0') {
        count = 0;
        check2 = false;
        break;
      }
    }
    if (check2)
      count++;
    if (count == temp) {
      check = true;
      break;
    }
  }
 
  if (check)
    d[k] = temp;
  else
    d[k] = temp - 1;
  return d[k];
}
