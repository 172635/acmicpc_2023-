#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    if(n == 2){
        int a[4];
        for(int i=0;i<4;i++){
            scanf("%d", &a[i]);
        }
        printf("%d %d\n", a[1]/2, a[1]/2);
        return 0;
    }
    int * ar = (int *)malloc(sizeof(int) * n);
    int a23;
    for(int i=0;i<n*n;i++){
        int x;
        scanf("%d", &x);
        if(i < n){
            ar[i] = x;
        }else if(i == n+2){
            a23 = x;
        }
    }
    int a0 = (ar[1]+ar[2] - a23)/2;
    printf("%d", a0);
    for(int i=1;i<n;i++){
        printf(" %d", ar[i] - a0);
    }
    printf("\n");
    return 0;
}