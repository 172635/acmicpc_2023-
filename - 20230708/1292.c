#include <stdio.h>

int num(int);

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", num(b) - num(a-1));
    return 0;
}

int num(int n){
    if(n==0){return 0;}
    int i = 1;
    while(i*(i+1)/2 <= n){
        i++;
    }
    i--;
    return i*(i+1)*(2*i+1)/6 + (i+1) * (n-i*(i+1)/2);
}