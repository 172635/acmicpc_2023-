#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int * tro = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d", &tro[i]);
    }
    int leftN = 0;
    int left = 0;
    int rightN = 0;
    int right = 0;
    for(int i=0;i<n;i++){
        if(left < tro[i]){
            leftN ++;
            left = tro[i];
        }
    }
    for(int i=n-1;i>=0;i--){
        if(right < tro[i]){
            rightN ++;
            right = tro[i];
        }
    }
    printf("%d\n%d\n", leftN, rightN);
    return 0;
}