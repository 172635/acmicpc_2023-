#include <stdio.h>

int main(){
    int n, s;
    scanf("%d %d", &n, &s);
    int ar[20];
    int ch[20];
    for(int i=0;i<n;i++){
        scanf("%d", &ar[i]);
        ch[i] = 0;
    }
    int sum = 0;
    int x = n-1;
    int num = 0;
    while(x>=0){
        if(sum == s){
            num ++;
        }
        while(x>=0){
            if(ch[x] == 0){
                sum += ar[x];
                ch[x] = 1;
                x = n-1;
                break;
            }else{
                sum -= ar[x];
                ch[x] = 0;
                x--;
            }
        }
    }
    if(s == 0){
        num --;
    }
    printf("%d\n", num);
    return 0;
}