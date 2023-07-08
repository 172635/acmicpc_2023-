#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int f;
    scanf("%d", &f);
    n -= n % 100;
    int rest = n % f;
    printf("%02d\n", (f - rest)%f);
    return 0;
}