#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int x;
        scanf("%d", &x);
        if((x+1) % (x%100) == 0){
            printf("Good\n");
        }else{
            printf("Bye\n");
        }
    }
}