#include <stdio.h>

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int c[10];
    for(int i=0;i<n;i++){
        scanf("%d", &c[i]);
    }
    int min_c = 0;
    for(int i=n-1;i>=0;i--){
        min_c += k/c[i];
        k %= c[i];
    }
    printf("%d", min_c);
    return 0;
}