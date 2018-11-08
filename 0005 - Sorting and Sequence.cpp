// https://acmp.ru/index.asp?main=source&id=6852780

#include <bits/stdc++.h>
 
using namespace std;
 
 
int main() {
 
    int n, a, odd = 0;
 
    vector<int> even;
 
 
    freopen("INPUT.TXT", "r", stdin);
    freopen("OUTPUT.TXT", "w", stdout);
    scanf("%d", &n);
 
 
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a % 2) {
            odd++;
            printf("%d ", a);
        } else
            even.push_back(a);
    }
    if (even.size() != n)
        printf("\n");
 
    for (int i = 0; i < even.size(); i++) {
        printf("%d ", even[i]);
        if (i == even.size() - 1)
            printf("\n");
    }
 
 
    if (even.size() >= odd)
        printf("YES");
    else
        printf("NO");
 
    return 0;
}
