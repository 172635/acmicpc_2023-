#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int x = 0;
    int ar[10];
    ar[0] = 0;
    while(n > 0){
        int ind = 0;
        while(1){
            if((ind < x && ar[ind] < ar[ind+1] - 1) || (ind == x && ar[ind] < 9) || ind > x){
                break;
            }
            ind ++;
        }
        if(ind > x){
            x = ind;
            ar[ind] = ind;
            if(x >= 10){
                break;
            }
        }else{
            ar[ind] ++;
        }
        for(int i=0;i<ind;i++){
            ar[i] = i;
        }
        n --;
    }
    if(x >= 10){
        printf("-1\n");
        return 0;
    }
    for(int i=x; i>=0; i--){
        printf("%d", ar[i]);
    }
    printf("\n");
    return 0;
}