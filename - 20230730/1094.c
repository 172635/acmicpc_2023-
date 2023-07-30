#include <stdio.h>

int main(){
    int x;
    scanf("%d", &x);
    int n = 64;
    int num = 0;
    while(x > 0){
        if(n <= x){
            x -= n;
            num ++;
        }
        n /= 2;
    }
    printf("%d\n", num);
    return 0;
}