#include <stdio.h>

int main(){
    int check[30];
    for(int i=0;i<30;i++){
        check[i] = 0;
    }
    for(int i=0;i<28;i++){
        int x;
        scanf("%d", &x);
        check[x-1] = 1;
    }
    for(int i=0;i<30;i++){
        if(check[i] == 0){
            printf("%d\n", i+1);
        }
    }
    return 0;
}