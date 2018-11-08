// https://acmp.ru/index.asp?main=source&id=8446841

#include <iostream>
#include <algorithm>
using namespace std;
 
int n, a[251][251], d[251][251], path[251][251][2]; 
char ans[251][251];
int calc(int, int);
 
int main() {  
  // read
  freopen("input.txt", "r", stdin);
  cin >> n;  
  for(int i = 1; i <= n; i++) {
    string temp;
    cin >> temp;
    for (int j = 0; j < n; j++) {
      a[i][j + 1] = temp[j] - 48;
      d[i][j + 1] = -1;
      ans[i][j + 1] = '.';
    }
  } 
   
  // start
  // initial
  ans[n][n] = ans[1][1] = '#';
  d[2][1] = a[1][1] + a[2][1], d[1][2] = a[1][1] + a[1][2], d[1][1] = a[1][1];  
  calc(n, n);
   
  int x = n, y = n, xx, yy;
  for(int i = 1; i <= 2 * n - 1; i++) {
    ans[xx = path[x][y][0]][yy = path[x][y][1]] = '#';
    x = xx, y = yy;
  }
 
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++)
      cout << ans[i][j];
    cout << endl;
  }
   
  return 0;
}
 
int calc(int i, int j) {
  if (i > n || j > n || i < 1 || j < 1) return INT32_MAX;
  if (d[i][j] != -1) return d[i][j];
   
  int l = calc(i - 1, j), r = calc(i, j - 1);
  if (l > r) {
    path[i][j][0] = i, path[i][j][1] = j - 1;
    d[i][j] = r + a[i][j];    
  } else {
    path[i][j][0] = i - 1, path[i][j][1] = j;
    d[i][j] = l + a[i][j];
  }
  return d[i][j];
}
