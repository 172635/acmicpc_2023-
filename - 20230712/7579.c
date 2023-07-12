#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int * mV = (int *)malloc(sizeof(int)*n);
    int * cV = (int *)malloc(sizeof(int)*n);
    
    int mMax = 0;
    for(int i=0;i<n;i++){
        scanf("%d", &mV[i]);
        if(mV[i] > mMax){
            mMax = mV[i];
        }
    }
    for(int i=0;i<n;i++){
        scanf("%d", &cV[i]);
    }
    
    short * nowMin = (short *)malloc(sizeof(short)*(m+mMax));
    short * prevMin;
    nowMin[0] = 0;
    for(int i=1;i<m+mMax;i++){
        nowMin[i] = -1;
    }
    for(int i=0;i<n;i++){
        free(prevMin);
        prevMin = nowMin;
        nowMin = (short *)malloc(sizeof(short)*(m+mMax));
        for(int j=0;j<m+mMax;j++){
            nowMin[j] = prevMin[j];
            if(j - mV[i] >= 0 && j - mV[i] < m && prevMin[j - mV[i]] != -1 && (prevMin[j - mV[i]] + (short)cV[i] < nowMin[j] || nowMin[j] == -1)){
                nowMin[j] = prevMin[j - mV[i]] + (short)cV[i];
            }
        }
    }
    int costMin = 100000;
    for(int i=m;i<m+mMax;i++){
        if(nowMin[i] != -1 && costMin > nowMin[i]){
            costMin = (int)nowMin[i];
        }
    }
    printf("%d\n", costMin);
}