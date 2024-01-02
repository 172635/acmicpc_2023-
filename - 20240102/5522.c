#include <stdio.h>

int main(){
    int sum = 0;
    int x;
    for(int i=0;i<5;i++){
        scanf("%d", &x);
        sum += x;
    }
    printf("%d\n", sum);
    return 0;
}