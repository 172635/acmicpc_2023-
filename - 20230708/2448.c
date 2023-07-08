#include <stdio.h>

void star(int, int);

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        star(i, n);
        printf("\n");
    }
    return 0;
}

void star(int i, int n){
    if(n == 3){
        if(i == 0){
            printf("  *  ");
        }else if(i == 1){
            printf(" * * ");
        }else{
            printf("*****");
        }

    }else if(i >= n / 2){
        star(i - n / 2, n / 2);
        printf(" ");
        star(i - n / 2, n / 2);
    }else{
        for(int j = 0; j < n / 2; j++){
            printf(" ");
        }
        star(i, n / 2);
        for(int j = 0; j < n / 2; j++){
            printf(" ");
        }
    }
}