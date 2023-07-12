#include <stdio.h>

int main(){
    int sum = 0;
    for(int i=0;i<5;i++){
        int x;
        scanf("%d", &x);
        sum += x*x;
        sum %= 10;
    }
    printf("%d\n", sum);
    return 0;
}