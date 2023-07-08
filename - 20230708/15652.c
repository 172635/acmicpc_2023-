#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int a[8];
    for(int i=0;i<m;i++){
        a[i] = 1;
    }
    while(1){
        for(int i=0;i<m;i++){
            if(i != m-1){
                printf("%d ", a[i]);
            }else{
                printf("%d\n", a[i]);
            }
        }
        a[m - 1]++;
        for(int i=m-1;i>=0;i--){
            if(a[i] == n+1){
                a[i-1]++;
            }else{
                for(int j=i+1;j<m;j++){
                    a[j] = a[i];
                }
                break;
            }
        }
        if(a[0] == n+1){
            break;
        }
    }
    return 0;
}