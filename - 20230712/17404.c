#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int cost[1001][3];
    for(int i=1;i<=n;i++){
        scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
    }
    int ffcost = 10000000;
    for(int s=0;s<3;s++){
        int costSum[1001][3];
        for(int i=0;i<3;i++){
            if(s == i){
                costSum[1][i] = cost[1][i];
            }else{
                costSum[1][i] = 1000000;
            }
        }
        for(int i=2;i<=n;i++){
            costSum[i][0] = (costSum[i-1][1] < costSum[i-1][2] ? costSum[i-1][1] : costSum[i-1][2]) + cost[i][0];
            costSum[i][1] = (costSum[i-1][0] < costSum[i-1][2] ? costSum[i-1][0] : costSum[i-1][2]) + cost[i][1];
            costSum[i][2] = (costSum[i-1][0] < costSum[i-1][1] ? costSum[i-1][0] : costSum[i-1][1]) + cost[i][2];
        }
        int finalcost = 10000000;
        for(int i=0;i<3;i++){
            if(s == i){
                continue;
            }
            finalcost = (finalcost < costSum[n][i] ? finalcost : costSum[n][i]);
        }
        if(ffcost > finalcost){
            ffcost = finalcost;
        }
    }
    printf("%d\n", ffcost);
    return 0;
}
