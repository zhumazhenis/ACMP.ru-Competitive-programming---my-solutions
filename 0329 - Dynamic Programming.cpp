// https://acmp.ru/index.asp?main=source&id=8445569

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
/*
g++ b.cpp -o b && b
*/
int n, *a, *d;
 
int main() {
  // read
  freopen("input.txt", "r", stdin);
  cin >> n;
  a = new int[n + 1];
  d = new int[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
 
  // start
  int path[n + 1];
  d[1] = a[1], path[1] = 0;
  // initial
  if (a[2] >= d[1] + a[2])
    d[2] = a[2], path[2] = 0;
  else
    d[2] = d[1] + a[2], path[2] = 1;
 
  for (int i = 3; i <= n; i++) {
    if (d[i - 1] >= d[i - 2]) {
      d[i] = d[i - 1] + a[i];
      path[i] = i - 1;
    } else {
      d[i] = d[i - 2] + a[i];
      path[i] = i - 2;
    }
  }
 
  int temp = n;
  vector<int> v;
  v.push_back(n);
  while (path[temp] != 0) v.push_back(temp = path[temp]);
  reverse(v.begin(), v.end());
 
  // print
  cout << d[n] << endl;
  for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
    cout << *i << " ";
 
  return 0;
}
