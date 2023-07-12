#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int check[26];
    for(int i=0;i<26;i++){
        check[i] = 0;
    }
    char temp;
    scanf("%c", &temp);
    for(int j=0;j<n;j++){
        char str[70];
        int c = 0;
        char ch = getchar();
        while(ch!='\n'){
            str[c] = ch;
            ch = getchar();
            c++;
        }
        str[c] = '\0';
        int checkstr[70];
        for(int i=0;i<c;i++){
            if(i == 0){
                checkstr[i] = 1;
            }else if(str[i-1] == ' '){
                checkstr[i] = 1;
            }else if(str[i] == ' '){
                checkstr[i] = 0;
            }else{
                checkstr[i] = 2;
            }
        }
        int strcount = -1;
        for(int i=0;i<c;i++){
            if(checkstr[i] != 1){
                continue;
            }
            int chn;
            if(str[i] >= 'a'){
                chn = str[i] - 'a';
            }else{
                chn = str[i] - 'A';
            }
            if(check[chn] == 0){
                check[chn] = 1;
                strcount = i;
                break;
            }
        }
        if(strcount == -1){
            for(int i=0;i<c;i++){
                if(checkstr[i] != 2){
                    continue;
                }
                int chn;
                if(str[i] >= 'a'){
                    chn = str[i] - 'a';
                }else{
                    chn = str[i] - 'A';
                }
                if(check[chn] == 0){
                    check[chn] = 1;
                    strcount = i;
                    break;
                }
            }
        }
        for(int i=0;i<c;i++){
            if(strcount == i){
                printf("[%c]", str[i]);
            }else{
                printf("%c", str[i]);
            }
        }
        printf("\n");
    }
    return 0;
}