#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    if(N%4 == 0 || N%4 == 2){
        printf("CY\n");
    }else{
        printf("SK\n");
    }
    return 0;
}