#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    while(n!=0){
        if(n>=10000){
            if(n/10000 == n%10 && n%10000/1000 == n%100/10){
                printf("yes\n");
            }else{
                printf("no\n");
            }
        }else if(n>=1000){
            if(n/1000 == n%10 && n%1000/100 == n%100/10){
                printf("yes\n");
            }else{
                printf("no\n");
            }
        }else if(n>=100){
            if(n/100 == n%10){
                printf("yes\n");
            }else{
                printf("no\n");
            }
        }else if(n>=10){
            if(n/10 == n%10){
                printf("yes\n");
            }else{
                printf("no\n");
            }
        }else{
            printf("yes\n");
        }
        scanf("%d", &n);
    }
    return 0;
}