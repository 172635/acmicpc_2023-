#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    if(n == 2 || n == 3){
        printf("-1\n");
        return 0;
    }
    if(n%6 == 2){
        for(int i=2;i<=n;i+=2){
            printf("%d\n", i);
        }
        printf("3\n1\n");
        for(int i=7;i<=n;i+=2){
            printf("%d\n", i);
        }
        printf("5\n");
    }else if(n%6 == 3){
        for(int i=4;i<=n;i+=2){
            printf("%d\n", i);
        }
        printf("2\n");
        for(int i=5;i<=n;i+=2){
            printf("%d\n", i);
        }
        printf("1\n3\n");
    }else{
        for(int i=2;i<=n;i+=2){
            printf("%d\n", i);
        }
        for(int i=1;i<=n;i+=2){
            printf("%d\n", i);
        }
    }
    return 0;
}