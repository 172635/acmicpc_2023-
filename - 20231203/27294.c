#include <stdio.h>

int main(){
    int t, s;
    scanf("%d %d",&t,&s);
    int lunch;
    if(t >= 12 && t <= 16){
        lunch = 1;
    }else{
        lunch = 0;
    }
    if(s == 1 || lunch == 0){
        printf("%d\n", 280);
    }else{
        printf("%d\n", 320);
    }
    return 0;
}