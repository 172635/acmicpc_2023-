#include <stdio.h>

int main(){
    int x[4];
    int y[4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            scanf("%d %d", &x[j], &y[j]);
        }
        if(x[1] < x[2] || x[3] < x[0] || y[1] < y[2] || y[3] < y[0]){
            printf("d\n");
        }else if((x[1] == x[2] && y[1] == y[2])||(x[1] == x[2] && y[0] == y[3])||(x[0] == x[3] && y[1] == y[2])||(x[0] == x[3] && y[0] == y[3])){
            printf("c\n");
        }else if(((x[1] == x[2] || x[0] == x[3]) && y[1] > y[2] && y[0] < y[3])||((y[1] == y[2] || y[0] == y[3]) && x[1] > x[2] && x[0] < x[3])){
            printf("b\n");
        }else{
            printf("a\n");
        }
    }
    return 0;
}