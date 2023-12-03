#include <stdio.h>

int main(){
    int m = -10000000;
    for(int i=0;i<2;i++){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if(a + b + c + d > m){
            m = a + b + c + d;
        }
    }
    printf("%d\n", m);
    return 0;
}