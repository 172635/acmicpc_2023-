#include <stdio.h>

void star(int, int);

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        star(i, n);
        printf("\n");
    }
}

void star(int i, int n){
    if(i == n){
        for(int j = 0; j < n; j++){
            printf(" ");
        }
        return;
    }
    if(n == 1){
        printf("*");
        return;
    }
    int k = n / 3;
    star(i % k, k);
    if(i / k == 1){
        star(k, k);
    }else{
        star(i % k, k);
    }
    star(i % k, k);
}