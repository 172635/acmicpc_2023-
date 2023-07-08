#include <stdio.h>

int main(){
    int h, m;
    scanf("%d %d", &h, &m);
    int pm;
    scanf("%d", &pm);
    h += pm/60;
    m += pm%60;
    if(m>=60){h++; m-=60;}
    h = h%24;
    printf("%d %d\n", h, m);
    return 0;
}