#include <stdio.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%.10f", (double)a/(double)b);
    scanf("%d", a);
    return 0;
}