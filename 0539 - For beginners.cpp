// https://acmp.ru/index.asp?main=source&id=6682561

#include <stdio.h>
 
int main() {
 
    int a;
 
    freopen("INPUT.txt","r",stdin);
    freopen("OUTPUT.txt","w",stdout);
    scanf("%d",&a);
 
    if(a == 1) 
        printf("%d", 0);
    else if ((a % 2) == 0)
        printf("%d", a / 2);
    else
        printf("%d", a);
 
 
    return 0;
}
