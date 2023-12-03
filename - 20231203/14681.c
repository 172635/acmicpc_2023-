#include <stdio.h>

int main(){
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    if(y > 0){
        if(x > 0){
            printf("%d\n", 1);
        }else{
            printf("%d\n", 2);
        }
    }else{
        if(x < 0){
            printf("%d\n", 3);
        }else{
            printf("%d\n", 4);
        }
    }
    return 0;
}