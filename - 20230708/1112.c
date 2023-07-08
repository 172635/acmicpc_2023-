#include <stdio.h>

int main(){
    int x, b;
    scanf("%d %d", &x, &b);
    if(b > 0){
        if(x < 0){
            printf("-");
            x = -x;
        }
        int lis[40];
        int i;
        for(i=0;i<40;i++){
            lis[i] = x % b;
            x /= b;
            if(x == 0){
                break;
            }
        }
        for(;i>=0;i--){
            printf("%d", lis[i]);
        }
        printf("\n");
    }else{
        b = -b;
        int check = 0;
        if(x < 0){
            x = -x;
            check = 1;
        }
        int lis[40];
        int i;
        for(i=0;i<40;i++){
            lis[i] = x % b;
            x /= b;
            if(i%2!=0){
                lis[i] = b - lis[i];
                x++;
                if(lis[i] == b){
                    lis[i] = 0;
                    x--;
                }
            }
            if(x == 0){
                break;
            }
        }
        if(check == 1){
            for(int j=0;j<=i;j++){
                if(lis[j] == 0){
                    continue;
                }
                if(lis[j] < 0){
                    lis[j] = - lis[j];
                }else{
                    lis[j] = b - lis[j];
                    lis[j+1] --;
                    if(j == i){
                        i++;
                        lis[j+1] = -1;
                    }
                }
            }
        }
        for(;i>=0;i--){
            if(check == 1){
                if(lis[i] == 0){
                    continue;
                }else{
                    check = 0;
                }
            }
            printf("%d", lis[i]);
        }
        printf("\n");
    }
    return 0;
}