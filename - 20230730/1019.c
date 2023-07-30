#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int numc;
    for(int i=0;i<10;i++){
        numc = 0;
        long long int check = 1;
        if(i == 0){
            while(n >= check){
                numc += (n/(10 * check) -1) * check;
                if(n % (10 * check) / check >= i+1){
                    numc += check;
                }else if(n % (10 * check) / check == i){
                    numc += n % check + 1;
                }
                check *= 10;
            }
        }else{
            while(n >= check){
                numc += n/(10 * check) * check;
                if(n % (10 * check) / check >= i+1){
                    numc += check;
                }else if(n % (10 * check) / check == i){
                    numc += n % check + 1;
                }
                check *= 10;
            }
        }
        printf("%d ", numc);
    }
    printf("\n");
    return 0;
}