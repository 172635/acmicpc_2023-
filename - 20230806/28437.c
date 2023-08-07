#include <stdio.h>
#include <stdlib.h>

int main(){
    int MAX = 100001;
    int n;
    scanf("%d", &n);
    int * numD = (int *)malloc(sizeof(int) * MAX);
    for(int i=0;i<MAX;i++){
        numD[i] = 0;
    }
    for(int i=0;i<n;i++){
        int x;
        scanf("%d", &x);
        numD[x] = 1;
    }
    for(int i=1;i<MAX;i++){
        for(int j=2;i*j < MAX; j++){
            numD[i*j] += numD[i];
        }
    }

    int q;
    scanf("%d", &q);
    int * pr = (int *)malloc(sizeof(int) * q);
    for(int i=0;i<q;i++){
        int x;
        scanf("%d", &x);
        pr[i] = numD[x];
    }
    for(int i=0;i<q;i++){
        printf("%d ", pr[i]);
    }
    printf("\n");
    return 0;
}