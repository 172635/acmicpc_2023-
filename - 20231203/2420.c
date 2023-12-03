#include <stdio.h>

int main(){
    long long int a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", a > b ? a-b : b-a);
    return 0;
}