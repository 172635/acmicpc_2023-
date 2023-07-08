#include <stdio.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    int n = 1;
    int check = 0;
    while(b != a){
        if(b % 10 == 1){
            n ++;
            b /= 10;
        }else if(b % 2 == 1 || b == 0){
            check = 1;
            break;
        }else{
            n++;
            b /= 2;
        }
    }
    if(check == 1){
        printf("-1\n");
    }else{
        printf("%d\n", n);
    }
    return 0;
}