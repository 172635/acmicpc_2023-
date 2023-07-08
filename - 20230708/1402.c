// 0 = 0 * B > B = 0 + B
// -1 = -1 * 1 > 0 = -1 + 1
// -N = -N * 1 > -N+1 = -N + 1
// N = -N * -1 > -N-1 = -N + (-1)

#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        int x;
        scanf("%d", &x);
        printf("yes\n");
    }
    return 0;
}