#include <stdio.h>

int main(){
    int fibo[41];
    int n;
    scanf("%d", &n);
    int m;
    scanf("%d", &m);
    fibo[0] = 1;
    fibo[1] = 1;
    for(int i=2;i<=n;i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    int method = 1;
    int before = 0;
    for(int i=0;i<m;i++){
        int x;
        scanf("%d", &x);
        method *= fibo[x-before - 1];
        before = x;
    }
    method *= fibo[n-before];
    printf("%d\n", method);
    return 0;
}