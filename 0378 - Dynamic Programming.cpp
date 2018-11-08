// https://acmp.ru/index.asp?main=source&id=8526550

#include <iostream>
#include <set>
#include <vector>
using namespace std;
 
int a[501], d[50001];
 
int main() {
  freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    d[i] = 0;
  }
  d[0] = 1;
 
  // start
  vector<int> v;
  v.push_back(0);
 
  for (int i = 1; i <= n; i++) {
    vector<int> temp;
    for (auto x : v) {
      if (d[x + a[i]] == 0) {
        d[x + a[i]] = 1;
        temp.push_back(x + a[i]);
      }
    }
    v.insert(v.end(), temp.begin(), temp.end());
  }
 
  int count = 0;
  for (int i = 0; i <= 50001; i++) {
    count += d[i];
  }
  cout << count;
  return 0;
}
