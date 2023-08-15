#include <stdio.h>

int main(){
    while(1){
        int a, b;
        int eof = scanf("%d %d", &a, &b);
        if(eof == -1){
            break;
        }
        printf("%d\n", a+b);
    }
    return 0;
}