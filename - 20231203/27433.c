#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    long long int a = 1;
    for(int i=1;i<=n;i++){
        a *= i;
    }
    printf("%lld\n", a);
    return 0;
}