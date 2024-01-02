#include <stdio.h>

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int num = 0;
    int last = 0;
    while(n--){
        int ai;
        scanf("%d", &ai);
        if(last < ai){
            last = ai;
        }else if(last < ai + k){
            last = ai + k;
            num ++;
        }else{
            num = -1;
            break;
        }
    }
    printf("%d\n", num);
    return 0;
}