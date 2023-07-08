#include <stdio.h>

int main(){
    int n, m, b;
    scanf("%d %d %d", &n, &m, &b);
    int num = n*m;
    int gr[257];
    for(int i=0;i<257;i++){
        gr[i] = 0;
    }
    int sum = 0;
    int max = 0;
    for(int i=0;i<num;i++){
        int x;
        scanf("%d", &x);
        gr[x] ++;
        sum += x;
        if(max < x){
            max = x;
        }
    }
    int time = 0;
    while(max != 0){
        if(max*num - sum <= b){
            if(gr[max] * 2 >= num - gr[max]){
                time += max*num - sum;
                break;
            }
        }
        time += gr[max] * 2;
        b += gr[max];
        sum -= gr[max];
        gr[max - 1] += gr[max];
        max --;
    }
    printf("%d %d", time, max);
    return 0;
}