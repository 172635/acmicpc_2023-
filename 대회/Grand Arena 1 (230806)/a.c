#include <stdio.h>

int main(){
    int count[10];
    for(int i=0;i<10;i++){
        count[i] = 0;
    }
    for(int i=0;i<5;i++){
        int x;
        scanf("%d", &x);
        count[x] ++;
    }
    for(int i=0;i<10;i++){
        if(count[i] % 2 == 1){
            printf("%d\n", i);
        }
    }
    return 0;
}