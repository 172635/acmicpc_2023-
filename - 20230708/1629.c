#include <stdio.h>

long long int multirest(int, int, int);

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    a %= c;
    printf("%lld\n", multirest(a, b, c));
    return 0;
}

long long int multirest(int a, int b, int c){
    if(b == 0){
        return 1;
    }else if(b % 2 == 1){
        return (a * multirest(a, b - 1, c)) % c;
    }else{
        long long int x = multirest(a, b / 2, c);
        return (x * x) % c;
    }
}