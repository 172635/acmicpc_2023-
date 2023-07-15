#include <stdio.h>
#include <stdlib.h>

int main(){
    int g, p;
    scanf("%d %d", &g, &p);
    int * check = (int *)malloc(sizeof(int)*(g+1));
    int * indL = (int *)malloc(sizeof(int)*(g+1));
    int * indR = (int *)malloc(sizeof(int)*(g+1));
    for(int i=1;i<=g;i++){
        check[i] = 0;
        indL[i] = i;
        indR[i] = i;
    }
    int maxP = 0;
    for(int i=0;i<p;i++){
        int gi;
        scanf("%d", &gi);
        int gr = gi;
        while(indR[gr] != gr){
            int gr2 = indR[gr];
            indR[gr] = indR[indR[gr]];
            gr = gr2;
        }
        int gl = indL[gr];
        while(gl > 0){
            if(check[gl] == 0){
                indL[gi] = gl - 1;
                indL[gr] = gl - 1;
                indR[gl] = gr;
                check[gl] = 1;
                maxP++;
                break;
            }else{
                indR[gl] = gr;
                gl = indL[gl];
            }
        }
        if(gl <= 0){
            for(int j=1;j<p-i;j++){
                scanf("%d", &gi);
            }
            break;
        }
    }
    printf("%d\n", maxP);
    return 0;
}