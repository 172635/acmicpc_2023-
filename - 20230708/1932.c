#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int ** triS = (int **)malloc(sizeof(int *) * n);
    for(int i=0;i<n;i++){
        triS[i] = (int *)malloc(sizeof(int) * (i+1));
        for(int j=0;j<=i;j++){
            scanf("%d", &triS[i][j]);
        }
    }
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            triS[i-1][j] += triS[i][j] > triS[i][j+1] ? triS[i][j] : triS[i][j+1];
        }
    }
    printf("%d\n", triS[0][0]);
    return 0;
}