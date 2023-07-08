#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int cost[3];
    int costSum[1001][3];
    costSum[0][0] = 0;
    costSum[0][1] = 0;
    costSum[0][2] = 0;
    for(int i=1;i<=n;i++){
        scanf("%d %d %d", &cost[0], &cost[1], &cost[2]);
        costSum[i][0] = (costSum[i-1][1] < costSum[i-1][2] ? costSum[i-1][1] : costSum[i-1][2]) + cost[0];
        costSum[i][1] = (costSum[i-1][0] < costSum[i-1][2] ? costSum[i-1][0] : costSum[i-1][2]) + cost[1];
        costSum[i][2] = (costSum[i-1][0] < costSum[i-1][1] ? costSum[i-1][0] : costSum[i-1][1]) + cost[2];
    }
    int finalcost = (costSum[n][0] < costSum[n][1] ? costSum[n][0] : costSum[n][1]);
    finalcost = (finalcost < costSum[n][2] ? finalcost : costSum[n][2]);
    printf("%d\n", finalcost);
    return 0;
}
