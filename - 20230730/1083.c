#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int * ar = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d", &ar[i]);
    }
    int s;
    scanf("%d", &s);
    int sindex = 0;
    while(s > 0 && sindex < n){
        int index = sindex;
        int maxN = 0;
        int maxI = index;
        while(index < n && index-sindex <= s){
            if(maxN < ar[index]){
                maxN = ar[index];
                maxI = index;
            }
            index ++;
        }
        s -= (maxI - sindex);
        for(int i=maxI;i>sindex;i--){
            ar[i] = ar[i-1];
        }
        ar[sindex] = maxN;
        sindex ++;
    }
    for(int i=0;i<n;i++){
        printf("%d ", ar[i]);
    }
    printf("\n");
    return 0;
}