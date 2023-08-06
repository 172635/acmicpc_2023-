#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int sum = 0;
    int num = 0;
    for(int i=1; i<=n; i++){
        sum += i;
        if(sum > n){
            break;
        }
        if((n - sum)%i == 0){
            num ++;
        }
    }
    printf("%d\n", num);
    return 0;
}