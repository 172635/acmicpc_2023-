#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int knife = 0;
    int knife_mul = 1;
    while(n >= m){
        n -= m;
    }
    int k = 2;
    while(k <= m){
        if(n % k == 0 && m % k == 0){
            n /= k;
            m /= k;
            knife_mul *= k;
        }else{
            k ++;
        }
    }
    knife = m - 1;
    knife *= knife_mul;
    printf("%d\n", knife);
    return 0;
}