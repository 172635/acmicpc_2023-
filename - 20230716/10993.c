#include <stdio.h>

int nk[12];
int N;

void tri(int, int);

int main(){
    scanf("%d", &N);
    nk[1] = 1;
    for(int i=2;i<=N;i++){
        nk[i] = nk[i-1] * 2 + 1;
    }
    for(int i=0;i<nk[N];i++){
        tri(N, i);
        printf("\n");
    }
}

void tri(int n, int i){
    if(n % 2 == 0){
        if(i == 0){
            for(int c=0;c<nk[n]*2-1;c++){
                printf("*");
            }
        }else{
            for(int c=0;c<i;c++){
                printf(" ");
            }
            printf("*");
            if(i <= nk[n-1]){
                for(int c=0;c<nk[n-1]-i;c++){
                    printf(" ");
                }
                tri(n-1, i-1);
                for(int c=0;c<nk[n-1]-i;c++){
                    printf(" ");
                }
            }else{
                for(int c=0;c<(nk[n]-i-1)*2-1;c++){
                    printf(" ");
                }
            }
            if(i != nk[n] - 1){
                printf("*");
            }
            if(n != N){
                for(int c=0;c<i;c++){
                    printf(" ");
                }
            }
        }
    }else{
        if(i == nk[n] -1){
            for(int c = 0;c<nk[n]*2-1;c++){
                printf("*");
            }
        }else{
            for(int c=0;c<nk[n]-i-1;c++){
                printf(" ");
            }
            printf("*");
            if(i < nk[n-1]){
                for(int c=0;c<i*2-1;c++){
                    printf(" ");
                }
            }else{
                for(int c=0;c<i-nk[n-1];c++){
                    printf(" ");
                }
                tri(n-1, i-nk[n-1]);
                for(int c=0;c<i-nk[n-1];c++){
                    printf(" ");
                }
            }
            if(i != 0){
                printf("*");
            }
            if(n != N){
                for(int c=0;c<nk[n]-i-1;c++){
                    printf(" ");
                }
            }
        }
    }
}