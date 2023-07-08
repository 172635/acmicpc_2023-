#include <stdio.h>

int main(){
    int c;
    scanf("%d", &c);
    char cmd[100001];
    int n;
    char xn[100000];
    int t_c;
    char temp;
    int temp2;
    int dir, min, max;//dir : 0> 1<
    int j;
    for(int i=0;i<c;i++){
        scanf("%s", cmd);
        scanf("%d", &n);
        dir = 0, min = 0, max = 0;
        t_c = 0;
        temp = 0;
        temp2 = 0;//check []
        while(temp!=']'){
            temp = getchar();
            switch(temp){
            case '[':
                temp2 = 1;
                t_c = 0;
                break;
            case ',':
            case ']':
                xn[max] = t_c;
                max++;
                t_c = 0;
                break;
            default:
                temp2 = 0;
                t_c = t_c * 10 + temp - 48;
                break;
            }
        }
        if(temp2 == 1){
            max--;
        }

        j = 0;
        while(1){
            if(cmd[j] == 'R'){
                dir  = 1 - dir;
            }else if(cmd[j] == 'D'){
                if(dir == 0){
                    min ++;
                }else{
                    max --;
                }
            }else{
                break;
            }
            j++;
        }
        
        if(min>max){
            printf("error\n");
        }else if(min==max){
            printf("[]\n");
        }else{
            max --;
            printf("[");
            if(dir == 0){
                for(j=min;j<max;j++){
                    printf("%d,", xn[j]);
                }
                printf("%d", xn[max]);
            }else{
                for(j=max;j>min;j--){
                    printf("%d,", xn[j]);
                }
                printf("%d", xn[min]);
            }
            printf("]\n");
        }
    }
    return 0;
}