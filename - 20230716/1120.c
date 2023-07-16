#include <stdio.h>

int cmp(char *, char *, int, int);

int main(){
    char a[60];
    char b[60];
    scanf("%s %s", a, b);
    int alen;
    int blen;
    for(int i=0;i<60;i++){
        if(a[i] == '\0'){
            alen = i;
            break;
        }
    }
    for(int i=0;i<60;i++){
        if(b[i] == '\0'){
            blen = i;
            break;
        }
    }
    int diff;
    if(alen < blen){
        diff = cmp(b, a, blen, alen);
    }else{
        diff = cmp(a, b, alen, blen);
    }
    printf("%d\n", diff);
}

int cmp(char * a, char * b, int alen, int blen){
    int diff = 50;
    for(int init=0;init<=alen-blen;init++){
        int td = 0;
        for(int c=0;c<blen;c++){
            if(a[init+c] != b[c]){
                td ++;
            }
        }
        if(diff > td){
            diff = td;
        }
    }
    return diff;
}