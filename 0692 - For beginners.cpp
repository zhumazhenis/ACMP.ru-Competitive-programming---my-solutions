// https://acmp.ru/index.asp?main=source&id=6682574

#include <stdio.h>
 
int main() {
 
    int a;
 
    freopen("INPUT.txt","r",stdin);
    freopen("OUTPUT.txt","w",stdout);
    scanf("%d",&a);
 
    if(a == 0) {
        printf("%s", "NO");
        return 0;
    }
     
    while((a % 2) == 0) {
        a = a / 2;
    }
 
    if (a == 1) {
        printf("%s", "YES");
        return 0;
    }
    else {
        printf("%s", "NO");
        return 0;
    }
         
}
