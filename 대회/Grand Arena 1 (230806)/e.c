#include <stdio.h>
#include <stdlib.h>

int main(){
    int REST = 1000000007;
    int n, k;
    scanf("%d %d", &n, &k);

    int * restN = (int *)malloc(sizeof(int) * k);
    for(int i=0;i<k;i++){
        restN[i] = 0;
    }
    for(int i=0;i<n;i++){
        int x;
        scanf("%d", &x);
        restN[x % k] ++;
    }
    int * pow2k = (int *)malloc(sizeof(int)*100000);
    pow2k[0] = 1;
    for(int i=1;i<100000;i++){
        pow2k[i] = (pow2k[i-1] * 2) % REST;
    }

    long long int zero = restN[0];
    long long int half = (k % 2 == 1 ? 0 : restN[k/2]);
    long long int num2 = 0;
    long long int num1 = 0;
    long long int num0 = 1;

    int half_i = (k % 2 == 1 ? k/2+1 : k/2);
    for(int i=1;i<half_i;i++){
        int a = restN[i];
        int b = restN[k - i];

        long long int n2 = pow2k[a] - a - 1 + pow2k[b] - b - 1;
        long long int n1 = a + b;
        long long int n0 = 1;
        num2 = n2*((num2 + num1 + num0) % REST) + n1*((num2 + num1) % REST) + n0*(num2);
        num2 %= REST;
        num1 = n1*(num0) + n0*(num1);
        num0 = n0*(num0);
    }
    int pr = (num2 * (((zero + 1) * (half + 1)) % REST) + num1 * ((zero + half + zero * half) % REST) + num0 * ((zero * half) % REST)) % REST;
    printf("%d\n", pr);
    return 0;
}