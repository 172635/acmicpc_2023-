#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    char field[51][51];
    for(int i=0;i<n;i++){
        scanf("%s", field[i]);
    }
    int sq = 1;
    int min = n < m ? n : m;
    for(int t=2;t<=min;t++){
        for(int i=0;i<n-t+1;i++){
            for(int j=0;j<m-t+1;j++){
                if(field[i][j] == field[i+t-1][j] && field[i][j] == field[i][j+t-1] && field[i][j] == field[i+t-1][j+t-1]){
                    sq = t;
                    i = n;
                    break;
                }
            }
        }
    }
    printf("%d\n", sq * sq);
    return 0;
}