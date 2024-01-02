#include <stdio.h>

int main(){
    int s1, s2, s3;
    scanf("%d %d %d", &s1, &s2, &s3);
    int t[100];
    for(int i=1;i<100;i++){
        t[i] = 0;
    }
    for(int i=1;i<=s1;i++){
        for(int j=1;j<=s2;j++){
            for(int k=1;k<=s3;k++){
                t[i+j+k] ++;
            }
        }
    }
    int maxN = 0;
    int maxV = 0;
    for(int i=1;i<100;i++){
        if(maxN < t[i]){
            maxN = t[i];
            maxV = i;
        }
    }
    printf("%d\n", maxV);
    return 0;
}