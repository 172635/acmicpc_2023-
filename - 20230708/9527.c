#include <stdio.h>

long long int one(long long int);

int main(){
    long long int a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", one(b) - one(a-1));
}

long long int one(long long int n){
    n++;
    long long int k = 2;
    long long int oneN = 0;
    while(k < 2 * n){
        oneN += n / k * (k / 2) + (n % k - k / 2) * ((n % k) / (k / 2));
        k *= 2;
    }
    return oneN;
}