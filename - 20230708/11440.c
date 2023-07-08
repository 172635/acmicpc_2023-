#include <stdio.h>
#include <stdlib.h>

long long int* fibo(long long int);

int main(){
    long long int n;
    scanf("%lld", &n);
    long long int * a = fibo(n);
    long long int sqr = a[0] * a[2] % 1000000007;
    printf("%lld\n", sqr);
    return 0;
}

long long int * fibo(long long int n){
    if(n == 1){
        long long int * r = (long long int *)malloc(sizeof(long long int)*4);
        r[0] = 1;
        r[1] = 1;
        r[2] = 1;
        r[3] = 0;
        return r;
    }
    if(n % 2 == 0){
        long long int * a = fibo(n/2);
        long long int * r = (long long int *)malloc(sizeof(long long int)*4);
        r[0] = (a[0] * a[0] + a[1] * a[2])%1000000007;
        r[1] = (a[0] * a[1] + a[1] * a[3])%1000000007;
        r[2] = (a[2] * a[0] + a[3] * a[2])%1000000007;
        r[3] = (a[2] * a[1] + a[3] * a[3])%1000000007;
        free(a);
        return r;
    }else{
        long long int * a = fibo(n-1);
        long long int * r = (long long int *)malloc(sizeof(long long int)*4);
        r[0] = (a[0] + a[1])%1000000007;
        r[1] = a[0];
        r[2] = (a[2] + a[3])%1000000007;
        r[3] = a[2];
        free(a);
        return r;
    }
}