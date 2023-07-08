#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int** PartialSum;
    PartialSum = (int**) malloc (sizeof(int*) * (n + 1));
    for(int i = 0; i < n + 1; i++){
        PartialSum[i] = (int*) malloc (sizeof(int) * (n + 1));
    }

    int x;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0){
                PartialSum[i][j] = 0;
                continue;
            }
            scanf("%d", &x);
            PartialSum[i][j] = PartialSum[i][j-1] + PartialSum[i-1][j] - PartialSum[i-1][j-1] + x;
        }
    }
    
    int sum;
    int x1, y1, x2, y2;
    for(int i=0;i<m;i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        sum = PartialSum[x2][y2] - PartialSum[x1 - 1][y2] - PartialSum[x2][y1 - 1] + PartialSum[x1 - 1][y1 - 1];
        printf("%d\n", sum);
    }
    return 0;
}