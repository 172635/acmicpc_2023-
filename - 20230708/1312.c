#include <stdio.h>

int main(){
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    a %= b;
    for(int i=0;i<n-1;i++){
        a *= 10;
        a %= b;
    }
    a *= 10;
    a /= b;
    printf("%d\n", a);
    return 0;
}