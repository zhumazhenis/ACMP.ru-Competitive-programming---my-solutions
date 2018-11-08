// https://acmp.ru/index.asp?main=source&id=7291557

#include <iostream>
 
using namespace std;
 
int main() {
 
    int n;
    int a, ans = 0;
 
    freopen("INPUT.TXT", "r", stdin);
    freopen("OUTPUT.TXT", "w", stdout);
    scanf("%d", &n);
 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a);
            ans += a;
        }
    }
 
    printf("%d", ans / 2);
 
    return 0;
}
