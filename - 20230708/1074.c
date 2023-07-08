#include <stdio.h>

int num(int, int, int);

int main(){
    int n, r, c;
    scanf("%d %d %d", &n, &r, &c);
    printf("%d\n", num(n, r, c));
    return 0;
}

int num(int n, int r, int c){
    if(n == 1){
        return r * 2 + c;
    }
    int m = 1 << (n - 1);
    return m*m * ((r>=m)*2+(c>=m)) + num(n-1, r % m, c % m);
}