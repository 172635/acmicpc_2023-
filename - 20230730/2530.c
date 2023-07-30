#include <stdio.h>

int main(){
    int a, b, c;
    int d;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d", &d);
    c += d;
    b += c / 60;
    c %= 60;
    a += b / 60;
    b %= 60;
    a %= 24;
    printf("%d %d %d\n", a, b, c);
    return 0;
}