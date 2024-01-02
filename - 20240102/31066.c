#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int a, b, c, d, k;
        scanf("%d %d %d", &a, &b, &k);
        if(b == 1 && k == 1 && a != 1){
            printf("-1\n");
        }else if(a == 1){
            printf("1\n");
        }else{
            int num = -1;
            while(a > 1){
                a = a - b * k + 1;
                num += 2;
            }
            printf("%d\n", num);
        }
    }
}