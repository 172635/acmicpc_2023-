#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n;
    scanf("%d\n", &n);
    int * solution = (int *)malloc(sizeof(int) * n);
    for(int i=0;i<n;i++){
        scanf("%d", &solution[i]);
    }
    int st = 0, en = n - 1;
    int a = st, b = en, min = solution[st] + solution[en];
    while(st < en){
        int tempmin = solution[st] + solution[en];
        if(abs(min) > abs(tempmin)){
            min = tempmin;
            a = st;
            b = en;
        }
        if(tempmin < 0){
            st ++;
        }else{
            en --;
        }
    }
    printf("%d %d\n", solution[a], solution[b]);
    return 0;
}