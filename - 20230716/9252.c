#include <stdio.h>
#include <stdlib.h>

int main(){
    char la[1001];
    char lb[1001];
    scanf("%s", la);
    scanf("%s", lb);
    int alen = 0;
    int blen = 0;
    for(int i=0;i<1001;i++){
        if(la[i] == '\0'){
            alen = i;
            break;
        }
    }
    for(int i=0;i<1001;i++){
        if(lb[i] == '\0'){
            blen = i;
            break;
        }
    }
    int ** alphaB = (int **)malloc(sizeof(int*)*('Z'-'A'+1));
    for(int i=0;i<='Z'-'A';i++){
        alphaB[i] = (int *)malloc(sizeof(int)*blen);
        int n = 0;
        int alphaN = -1;
        while(n < blen){
            if(lb[n] == 'A'+i){
                alphaN = n;
            }
            alphaB[i][n] = alphaN;
            n++;
        }
    }
    int ** strL = (int **)malloc(sizeof(int *)*alen+1);
    for(int a = 0; a <= alen; a++){
        strL[a] = (int *)malloc(sizeof(int)*blen+1);
        if(a == 0){
            for(int b = 0;b<=blen;b++){
                strL[a][b] = 0;
            }
            continue;
        }
        for(int b = 0; b <= blen; b++){
            strL[a][b] = strL[a-1][b];
            if(b == 0){
                continue;
            }
            if(strL[a][b] < strL[a][b-1]){
                strL[a][b] = strL[a][b-1];
            }
            int lastPos = alphaB[la[a-1] - 'A'][b-1];
            if(lastPos >= 0 && lastPos <= b && strL[a][lastPos] + 1 > strL[a][b]){
                strL[a][b] = strL[a-1][lastPos] + 1;
            }
        }
    }
    int len = strL[alen][blen];
    printf("%d\n", len);
    if(len > 0){
        char * str = (char *)malloc(sizeof(char)*len);
        int a = alen;
        int b = blen;
        int x = strL[a][b];
        int xn = 0;
        while(a > 0){
            if(strL[a-1][b] == x){
                a--;
            }else{
                str[xn] = la[a-1];
                xn ++;
                while(b > 0 && strL[a][b] == x){
                    b--;
                }
                x = strL[a][b];
            }
        }
        for(int i = len-1; i>=0; i--){
            printf("%c", str[i]);
        }
        printf("\n");
    }
    return 0;
}