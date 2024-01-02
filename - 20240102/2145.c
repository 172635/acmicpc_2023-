#include <stdio.h>

int main(){
    while(true){
        int x;
        scanf("%d", &x);
        if(x==0){
            break;
        }
        while(x >= 10){
            int y = 0;
            while(x >= 1){
                y += x % 10;
                x /= 10;
            }
            x = y;
        }
        printf("%d\n", x);
    }
    return 0;
}