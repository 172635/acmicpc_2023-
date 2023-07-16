#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int num[9];
    for(int i=0;i<9;i++){
        num[i] = 0;
    }
    while(n > 0){
        int x = n % 10;
        n /= 10;
        if(x == 9){
            num[6] ++;
        }else{
            num[x] ++;
        }
    }
    int mn = 0;
    for(int i=0;i<9;i++){
        if(i == 6){
            if(mn < (num[i] + 1)/2){
                mn = (num[i] + 1)/2;
            }
        }else if(mn < num[i]){
            mn = num[i];
        }
    }
    printf("%d\n", mn);
    return 0;
}