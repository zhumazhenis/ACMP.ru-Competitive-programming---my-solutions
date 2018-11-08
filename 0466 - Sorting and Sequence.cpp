// https://acmp.ru/index.asp?main=source&id=6680646

#include <stdio.h>
  
  
int juma(int i) {
  
    if(i == 1)
        return 1;
    if(i == 0)
        return 0;
  
    while((i%2) == 0) {
        i = i/2;
    }
  
    return juma(i/2) + juma(i - (i/2));
}
  
int main() {
    int a;
      
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&a);
  
    int answer_1 = juma(a);
     
    printf("%d", answer_1);
  
  
    return 0;
}
