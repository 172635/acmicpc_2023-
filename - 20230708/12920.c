#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int cost, happy, num;
    int * nowMax = (int *)malloc(sizeof(int)*(m+1));
    int * prevMax;
    for(int i=0;i<=m;i++){
        nowMax[i] = 0;
    }
    for(int i=0;i<n;i++){
        scanf("%d %d %d", &cost, &happy, &num);
        while(num > 0){
            int k = num % 2 == 0 ? num / 2 : (num+1)/2;
            free(prevMax);
            prevMax = nowMax;
            nowMax = (int *)malloc(sizeof(int)*(m+1));
            for(int j=0;j<=m;j++){
                nowMax[j] = prevMax[j];
                if(j - k*cost >= 0 && prevMax[j - k*cost] + happy*k > nowMax[j]){
                    nowMax[j] = prevMax[j - k*cost] + happy*k;
                }
            }
            num -= k;
        }
    }
    printf("%d\n", nowMax[m]);
    return 0;
}