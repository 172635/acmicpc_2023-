#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int * ar = (int *)malloc(sizeof(int)*(n+1));
    for(int i=1; i<n; i++){
        for(int j=i; j>1; j /= 2){
            ar[j] = ar[j/2];
        }
        ar[1] = i+1;
    }
    ar[n] = 1;
    for(int i=1; i<=n; i++){
        printf("%d ", ar[i]);
    }
    printf("\n");
    return 0;
}
