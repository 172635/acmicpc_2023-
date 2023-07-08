#include <stdio.h>

int alpha(int, int, int, int, int);

int main(){
    int n;
    int r1, c1, r2, c2;
    scanf("%d %d %d %d %d", &n, &r1, &c1, &r2, &c2);
    int rc = 2*n-1;
    r2 = r2 - r1 + 1;
    c2 = c2 - c1 + 1;
    r1 %= rc;
    c1 %= rc;
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            printf("%c", 'a'+alpha(n, i, j, r1, c1));
        }
        printf("\n");
    }
    return 0;
}

int alpha(int n, int r, int c, int r1, int c1){
    int rc = 2*n-1;
    r = (r + r1) % rc;
    c = (c + c1) % rc;
    if(r < n){
        if(c < n){
            if(r + c < n - 1){
                return '.' - 'a';
            }
            return ((2 * (n - 1) - r - c) % 26);
        }else{
            if(c - r >= n){
                return '.' - 'a';
            }
            return ((c - r) % 26);
        }
    }else{
        if(c < n){
            if(r - c >= n){
                return '.' - 'a';
            }
            return ((r - c) % 26);
        }else{
            if(r + c >= 3 * n - 2){
                return '.' - 'a';
            }
            return ((r + c - 2 * (n - 1)) % 26);
        }
    }
}