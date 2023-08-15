#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int fibo1;
    int fibo2;
    fibo1 = 1;
    fibo2 = 1;
    int ze = 1;
    int * zec = (int *)malloc(sizeof(int)*(n+1));
    while(ze <= n){
        if(ze >= fibo2){
            int temp = fibo1 + fibo2;
            fibo1 = fibo2;
            fibo2 = temp;
        }
        if(ze == fibo1){
            zec[ze] = ze;
        }else{
            zec[ze] = zec[ze-fibo1];
        }
        ze ++;
    }
    if(n == zec[n]){
        printf("-1\n");
    }else{
        printf("%d\n", zec[n]);
    }
    return 0;
}