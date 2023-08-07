#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    long long int * qn = (long long int *)malloc(sizeof(long long int) * (n+1));
    long long int * qm = (long long int *)malloc(sizeof(long long int) * (m+1));
    for(int i=1;i<=n;i++){
        qn[i] = 0;
    }
    for(int i=1;i<=m;i++){
        qm[i] = 0;
    }
    for(int i=0;i<q;i++){
        int op, c, v;
        scanf("%d %d %d", &op, &c, &v);
        if(op == 1){
            qn[c] += v;
        }else{
            qm[c] += v;
        }
    }
    for(int i=1;i<=n;i++){
        int qni = qn[i];
        for(int j=1;j<=m;j++){
            printf("%d ", qni+qm[j]);
        }
        printf("\n");
    }
    return 0;
}