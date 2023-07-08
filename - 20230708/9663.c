#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int set[15][3]; //y. x+y. x-y.
    int method = 0;
    int x = 1;
    for(int i=1;i<=n;i++){
        set[i][0] = 0;
        set[i][1] = i;
        set[i][2] = i;
    }
    while(x != 0){
        set[x][0]++;
        set[x][1]++;
        set[x][2]--;
        if(set[x][0] == n+1){
            set[x][0] = 0;
            set[x][1] = x;
            set[x][2] = x;
            x--;
            continue;
        }
        int check = 0;
        for(int i=1;i<x;i++){
            if(set[i][0] == set[x][0] || set[i][1] == set[x][1] || set[i][2] == set[x][2]){
                check = 1;
                break;
            }
        }
        if(check == 1){
            continue;
        }
        if(x == n){
            method ++;
        }else{
            x++;
        }
    }
    printf("%d\n", method);
    return 0;
}