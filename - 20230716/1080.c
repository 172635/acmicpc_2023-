#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int ar[50][50];
    for(int i=0;i<n;i++){
        char ch[50];
        scanf("%s", ch);
        for(int j=0;j<m;j++){
            ar[i][j] = ch[j] - '0';
        }
    }
    int ans[50][50];
    for(int i=0;i<n;i++){
        char ch[50];
        scanf("%s", ch);
        for(int j=0;j<m;j++){
            ans[i][j] = ch[j] - '0';
        }
    }
    int num = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ar[i][j] != ans[i][j]){
                if(i >= n-2 || j >= m-2){
                    num = -1;
                    i = n;
                    break;
                }
                num ++;
                for(int x=0;x<3;x++){
                    for(int y=0;y<3;y++){
                        ar[i+x][j+y] = 1 - ar[i+x][j+y];
                    }
                }
            }
        }
    }
    printf("%d\n", num);
    return 0;
}