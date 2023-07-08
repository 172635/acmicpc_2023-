#include <stdio.h>

int main(){
    int p[41][2];
    p[0][0] = 1;
    p[0][1] = 0;
    p[1][0] = 0;
    p[1][1] = 1;
    for(int i=2;i<41;i++){
        p[i][0] = p[i-2][0] + p[i-1][0];
        p[i][1] = p[i-2][1] + p[i-1][1];
    }

    int c;
    scanf("%d", &c);
    for(int i=0;i<c;i++){
        int n;
        scanf("%d", &n);
        printf("%d %d\n", p[n][0], p[n][1]);
    }
    return 0;
}