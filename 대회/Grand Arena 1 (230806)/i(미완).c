#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int ** ar = (int **)malloc(sizeof(int *)*n);
    int * zero = (int *)malloc(sizeof(int)*n);
    int maxZ = 0;
    for(int i=0;i<n;i++){
        ar[i] = (int *)malloc(sizeof(int)*m);
        zero[i] = 0;
        for(int j=0;j<m;j++){
            scanf("%d", &ar[i][j]);
            if(ar[i][j] == 0){
                zero[i] ++;
            }
        }
        if(zero[maxZ] < zero[i]){
            maxZ = i;
        }
    }
}

(n > m)