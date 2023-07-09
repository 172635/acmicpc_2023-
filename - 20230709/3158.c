#include <stdio.h>

int main(){
    char str[60];
    scanf("%s", str);
    int num[60];
    int e;
    for(e=1;str[e] != '\0';e++){
        num[e] = str[e] - '0';
    }
    e --;
    if(num[e] == 4){
        for(int i=1;i<=3;i++){
            printf("T");
            for(int j=1;j<e;j++){
                printf("%d", num[j]);
            }
            printf("%d\n", i);
        }
    }else{
        int check[3] = {0, 0, 0};
        for(int i=e;i>0;i--){
            if(check[num[i]-1] == 0){
                check[num[i]-1] = 1;
                printf("T");
                for(int j=1;j<i;j++){
                    printf("%d", num[j]);
                }
                printf("4\n");
            }
        }
    }
    return 0;
}