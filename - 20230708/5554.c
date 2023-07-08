#include <stdio.h>

int main(){
    int sum = 0;
    for(int i=0;i<4;i++){
        int x;
        scanf("%d", &x);
        sum += x;
    }
    printf("%d\n%d\n", sum/60, sum%60);
    return 0;
}