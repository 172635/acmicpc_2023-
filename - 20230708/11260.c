#include <stdio.h>
#include <stdlib.h>

int x[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int y[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int main(){
    while(1){
        int a, b;
        scanf("%d %d", &a, &b);
        if(a == 0){
            break;
        }
        char ** img = (char **)malloc(sizeof(char *)*a);
        for(int i=0;i<a;i++){
            img[i] = (char *)malloc(sizeof(char)*b);
            char str[105];
            scanf("%s", str);
            for(int j=0;j<b;j++){
                img[i][j] = str[j];
            }
        }
        int sum = 0;
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(img[i][j] == '#'){
                    int check = 0;
                    for(int k=0;k<8;k++){
                        if(i+x[k] < 0 || i+x[k] >= a || j+y[k] < 0 || j+y[k] >= b){
                            continue;
                        }
                        if(img[i+x[k]][j+y[k]] == '#'){
                            check = 1;
                            break;
                        }
                    }
                    if(check == 0){
                        sum ++;
                    }
                }
            }
        }
        printf("%d\n", sum);
        free(img);
    }
}