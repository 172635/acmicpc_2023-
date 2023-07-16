#include <stdio.h>

int main(){
    int n;
    scanf("%d\n", &n);
    int sum = 0;
    for(int i=0;i<n;i++){
        char ch = getchar();
        sum += ch - '0';
    }
    printf("%d\n", sum);
    return 0;
}