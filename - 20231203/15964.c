#include <stdio.h>

int main(){
    long long int a, b;
    scanf("%d %d", &a, &b);
    printf("%lld\n", (a+b)*(a-b));
    return 0;
}