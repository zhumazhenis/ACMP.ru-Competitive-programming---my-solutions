// https://acmp.ru/index.asp?main=source&id=6682577

#include <stdio.h>
 
int main() {
 
    int a, b, c;
 
    freopen("INPUT.txt","r",stdin);
    freopen("OUTPUT.txt","w",stdout);
    scanf("%d%d%d",&a, &b, &c);
 
    if((a <= 0)||(b <= 0)||(c <= 0)) {
        printf("%s", "NO");
        return 0;
    }
 
    double d = ((double)a*a-(double)b*b-(double)c*c)/2/b/c;
 
    if( ((d>=1)||(d<=-1))) {
        printf("%s", "NO");
        return 0;
    }
    else {
        printf("%s", "YES");
        return 0;
    }
 
}
