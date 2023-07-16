#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    if(n == 1){
        int sum = a + b + c + d + e + f;
        int max = 0;
        if(max < a){
            max = a;
        }
        if(max < b){
            max = b;
        }
        if(max < c){
            max = c;
        }
        if(max < d){
            max = d;
        }
        if(max < e){
            max = e;
        }
        if(max < f){
            max = f;
        }
        printf("%d\n", sum - max);
        return 0;
    }
    
    int d1, d2, d3;
    d1 = a < f ? a : f;
    d2 = b < e ? b : e;
    d3 = c < d ? c : d;
    if(d2 > d3){
        int temp = d2;
        d2 = d3;
        d3 = temp;
    }
    if(d1 > d2){
        int temp = d1;
        d1 = d2;
        d2 = temp;
    }
    if(d2 > d3){
        int temp = d2;
        d2 = d3;
        d3 = temp;
    }
    long long int sum = 0;
    sum += ((long long int)(n - 2)) * (n-2 + 4*(n-1)) * d1;
    sum += ((n-2) * 4 + (n-1) * 4) * (d1+d2);
    sum += 4 * (d1+d2+d3);
    printf("%lld\n", sum);
    return 0;
}