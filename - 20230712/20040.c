#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int * parent = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    for(int turn=1;;turn++){
        if(turn == m+1){
            printf("0\n");
            break;
        }
        int a, b;
        scanf("%d %d", &a, &b);
        int pa = parent[a];
        int pb = parent[b];
        while(pa != parent[pa]){
            pa = parent[pa];
            parent[a] = pa;
        }
        while(pb != parent[pb]){
            pb = parent[pb];
            parent[b] = pb;
        }

        if(pa == pb){
            for(int i=0;i<m-turn;i++){
                scanf("%d %d", &a, &b);
            }
            printf("%d\n", turn);
            break;
        }else if(pa > pb){
            parent[pb] = pa;
        }else{
            parent[pa] = pb;
        }
    }
    return 0;
}