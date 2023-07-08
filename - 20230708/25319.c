#include <stdio.h>
#include <stdlib.h>

typedef struct pointxy{
    int x;
    int y;
}point;

int main(){
    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);
    int gralpha[26];
    for(int i=0;i<26;i++){
        gralpha[i] = 0;
    }
    point ** grafield = (point **)malloc(sizeof(point*)*26);
    for(int i=0;i<26;i++){
        grafield[i] = (point *)malloc(sizeof(point)*2500);
    }
    for(int i=0;i<n;i++){
        char temp[52];
        scanf("%s", temp);
        for(int j=0;j<m;j++){
            temp[j] -= 'a';
            grafield[temp[j]][gralpha[temp[j]]].x = j;
            grafield[temp[j]][gralpha[temp[j]]].y = i;
            gralpha[temp[j]] ++;
        }
    }
    char str[1001];
    scanf("%s", str);
    int stalpha[26];
    for(int i=0;i<26;i++){
        stalpha[i] = 0;
    }
    int strab[1001][2]; // alpha / num
    for(int i=0;i<s;i++){
        strab[i][0] = str[i] - 'a';
        strab[i][1] = stalpha[str[i] - 'a'];
        stalpha[str[i] - 'a'] ++;
    }
    int rep = 3000;
    for(int i=0;i<26;i++){
        if(stalpha[i] != 0){
            if(rep > gralpha[i] / stalpha[i]){
                rep = gralpha[i] / stalpha[i];
            }
        }
    }
    printf("%d ", rep);

    char * cmd = (char *)malloc(sizeof(char)*1000000);
    int l = 0;
    int y = 0, x = 0;
    for(int i=0;i<rep;i++){
        for(int j=0;j<s;j++){
            int ab = strab[j][0];
            int abn = strab[j][1] + stalpha[ab] * i;
            int gy = grafield[ab][abn].y;
            int gx = grafield[ab][abn].x;
            for(int c=0;c<gy-y;c++){
                cmd[l] = 'D';
                l++;
            }
            for(int c=0;c<y-gy;c++){
                cmd[l] = 'U';
                l++;
            }
            for(int c=0;c<gx-x;c++){
                cmd[l] = 'R';
                l++;
            }
            for(int c=0;c<x-gx;c++){
                cmd[l] = 'L';
                l++;
            }
            cmd[l] = 'P';
            l++;
            x = gx;
            y = gy;
        }
    }
    for(int c=0;c<n-y-1;c++){
        cmd[l] = 'D';
        l++;
    }
    for(int c=0;c<m-x-1;c++){
        cmd[l] = 'R';
        l++;
    }
    printf("%d\n", l);
    for(int i=0;i<l;i++){
        printf("%c", cmd[i]);
    }
    printf("\n");
    return 0;
}