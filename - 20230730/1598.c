#include <stdio.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    int a1 = (a-1)%4+1;
    int a2 = (a-1)/4;
    int b1 = (b-1)%4+1;
    int b2 = (b-1)/4;
    int d1 = b1 - a1;
    if(d1 < 0){
        d1 = - d1;
    }
    int d2 = b2 - a2;
    if(d2 < 0){
        d2 = - d2;
    }
    printf("%d\n", d1+d2);
    return 0;
}