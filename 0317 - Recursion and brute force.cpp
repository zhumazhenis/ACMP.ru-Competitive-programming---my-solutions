// https://acmp.ru/index.asp?main=source&id=8532546

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
 
/*
 
g++ a.cpp -o a && a
 
*/
 
using namespace std;
int x, y, z, w;
 
int main() {
  freopen("input.txt", "r", stdin);
  int w;
  cin >> x >> y >> z >> w;
 
  // start
  int count = 0;
  for (int i = 0; i <= w / x; i++)
    for (int j = 0; j <= (w - x * i) / y; j++)
      if ((w - i * x - j * y) % z == 0) count++;
  cout << count;
  return 0;
}
