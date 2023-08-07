#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    char ** rec = (char **)malloc(sizeof(char *)*n);
    int quest;
    for(int i=0;i<n;i++){
        rec[i] = (char *)malloc(sizeof(char) * 11);
        scanf("%s", rec[i]);
        if(rec[i][0] == '?'){
            quest = i;
        }
    }
    int qfirst, qend;
    if(quest != 0){
        int len;
        for(len=0;rec[quest-1][len] != '\0';len++){
        }
        qfirst = rec[quest-1][len-1];
    }else{
        qfirst = -1;
    }
    if(quest != n-1){
        qend = rec[quest+1][0];
    }else{
        qend = -1;
    }

    int m;
    scanf("%d", &m);
    for(int i=0;i<m;i++){
        char hu[11];
        scanf("%s", hu);
        int len;
        for(len = 0; hu[len] != '\0'; len++){
        }
        int check = 0;
        if(qfirst != -1 && hu[0] != qfirst){
            check = 1;
        }
        if(qend != -1 && hu[len-1] != qend){
            check = 1;
        }
        if(check == 0){
            for(int j=0;j<n;j++){
                int jcheck = 1;
                for(int c=0;c<len+1;c++){
                    if(rec[j][c] != hu[c]){
                        jcheck = 0;
                        break;
                    }
                }
                if(jcheck == 1){
                    check = 1;
                    break;
                }
            }
            if(check == 0){
                printf("%s", hu);
            }
        }
    }
    return 0;
}