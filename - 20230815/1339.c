#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int alpha[26];
    for(int i=0;i<26;i++){
        alpha[i] = 0;
    }
    for(int i=0;i<n;i++){
        char st[10];
        scanf("%s", st);
        int len = 0;
        for(len=0;st[len] != '\0'; len++){}
        int t = 1;
        for(int j=1;j<=len;j++){
            alpha[st[len-j] - 'A'] += t;
            t *= 10;
        }
    }
    int a[10];
    for(int i=0;i<10;i++){
        a[i] = 0;
    }
    for(int i=0;i<26;i++){
        int ind = 9;
        while(ind >= 0 && alpha[i] > a[ind]){
            ind --;
        }
        ind ++;
        if(ind > 9){
            continue;
        }
        for(int j=9; j>ind; j--){
            a[j] = a[j-1];
        }
        a[ind] = alpha[i];
    }
    int sMax = a[0] * 9 + a[1] * 8 + a[2] * 7 + a[3] * 6 + a[4] * 5 + a[5] * 4 + a[6] * 3 + a[7] * 2 + a[8] * 1;
    printf("%d\n", sMax);
    return 0;
}