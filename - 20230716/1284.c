#include <stdio.h>

int main(){
    while(1){
        int n;
        scanf("%d", &n);
        if(n == 0){
            break;
        }
        int size = 1;
        while(n > 0){
            int x = n % 10;
            if(x == 1){
                size += 3;
            }else if(x == 0){
                size += 5;
            }else{
                size += 4;
            }
            n /= 10;
        }
        printf("%d\n", size);
    }
    return 0;
}