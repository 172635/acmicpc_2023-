#include <stdio.h>

int rm01(char *, int, int *, int);

int main(){
    int t;
    scanf("%d", &t);
    while(t > 0){
        char str[201];
        scanf("%s", str);
        int strN = 0;
        for(;str[strN] != '\0';strN++){}
        int rmP[100];
        int rmN = 0;
        for(int i=0;i<strN-1;i++){
            if(str[i] == '0' && str[i+1] == '1' && (i == 0 || str[i-1] == '1')){
                rmP[rmN] = i;
                rmN ++;
            }
        }
        strN = rm01(str, strN, rmP, rmN);
        str[strN] = '\0';
        while(strN > 0){
            if(str[strN - 1] == '0'){
                break;
            }else if(str[strN - 1] == '2'){
                strN --;
                continue;
            }
            while(strN > 0 && str[strN - 1] == '1'){
                strN --;
            }
            if(strN < 3 || str[strN - 2] == '1'){
                strN = 1;
                break;
            }
            while(strN > 0 && str[strN - 1] == '0'){
                strN --;
            }
            if(str[strN - 1] == '1'){
                strN --;
            }else{
                strN = 1;
                break;
            }
        }
        if(strN == 0){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
        t --;
    }
}

int rm01(char * nw, int nwN, int * rm, int rmN){
    for(int i = 1; i <= rmN; i++){
        int rmi = rm[rmN - i];
        nw[rmi] = '2';
        for(int j = rmi + 1; j < nwN - i; j++){
            nw[j] = nw[j+1];
        }
    }
    return nwN - rmN;
}