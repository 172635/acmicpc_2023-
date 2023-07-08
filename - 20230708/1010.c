#include <stdio.h>

int main(){
    int brid[31][31];
    for(int i=1;i<31;i++){
        for(int j=1;j<31;j++){
            if(i == 1){
                brid[i][j] = j;
                continue;
            }
            if(j < i){
                brid[i][j] = 0;
                continue;
            }
            brid[i][j] = brid[i-1][j-1] + brid[i][j-1];
        }
    }
    
    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", brid[a][b]);
    }
    return 0;
}