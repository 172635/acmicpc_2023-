#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        printf("Case #%d: %d\n", i, x+y);
    }
    return 0;
}