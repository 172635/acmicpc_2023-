#include <stdio.h>

int main(){
    char ch = getchar();
    int x = ch - '0';
    if(x >= 4){
        printf("1");
        x -= 4;
        if(x >= 2){
            printf("1");
            x -= 2;
        }else{
            printf("0");
        }
        if(x == 1){
            printf("1");
        }else{
            printf("0");
        }
    }else if(x >= 2){
        printf("1");
        x -= 2;
        if(x == 1){
            printf("1");
        }else{
            printf("0");
        }
    }else{
        printf("%d", x);
    }
    ch = getchar();
    while(ch != '\n'){
        x = ch - '0';
        if(x >= 4){
            printf("1");
            x -= 4;
        }else{
            printf("0");
        }
        if(x >= 2){
            printf("1");
            x -= 2;
        }else{
            printf("0");
        }
        if(x == 1){
            printf("1");
        }else{
            printf("0");
        }
        ch = getchar();
    }
    printf("\n");
    return 0;
}