#include <stdio.h>
#include <stdlib.h>

void CH(int *, int *, int);

int main(){
    int n;
    scanf("%d", &n);
    int *** dis = (int ***)malloc(sizeof(int **)*n);
    for(int i=0;i<n;i++){
        dis[i] = (int **)malloc(sizeof(int *)*5);
    }
    for(int i=0;i<5;i++){
        char temp[50];
        scanf("%s", temp);
        for(int j=0;j<n;j++){
            dis[j][i] = (int *)malloc(sizeof(int)*3);
            for(int k=0;k<3;k++){
                if(temp[j*4+k] == '.'){
                    dis[j][i][k] = 0;
                }else{
                    dis[j][i][k] = 1;
                }
            }
        }
    }
    double avgst = 0.0;
    for(int i=0;i<n;i++){
        avgst *= 10;
        double tempavg = 0.0;
        int tempn = 0;
        int check[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        if(dis[i][0][0] == 1){
            int ch[1] = {1};
            CH(check, ch, 1);
        }
        if(dis[i][0][1] == 1){
            int ch[2] = {1, 4};
            CH(check, ch, 2);
        }
        if(dis[i][1][0] == 1){
            int ch[4] = {1, 2, 3, 7};
            CH(check, ch, 4);
        }
        if(dis[i][1][1] == 1){
            int ch[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
            CH(check, ch, 10);
        }
        if(dis[i][1][2] == 1){
            int ch[2] = {5, 6};
            CH(check, ch, 2);
        }
        if(dis[i][2][0] == 1){
            int ch[2] = {1, 7};
            CH(check, ch, 2);
        }
        if(dis[i][2][1] == 1){
            int ch[3] = {0, 1, 7};
            CH(check, ch, 3);
        }
        if(dis[i][3][0] == 1){
            int ch[6] = {1, 3, 4, 5, 7, 9};
            CH(check, ch, 6);
        }
        if(dis[i][3][1] == 1){
            int ch[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
            CH(check, ch, 10);
        }
        if(dis[i][3][2] == 1){
            int ch[1] = {2};
            CH(check, ch, 1);
        }
        if(dis[i][4][0] == 1){
            int ch[3] = {1, 4, 7};
            CH(check, ch, 3);
        }
        if(dis[i][4][1] == 1){
            int ch[3] = {1, 4, 7};
            CH(check, ch, 3);
        }
        for(int j=0;j<10;j++){
            if(check[j] == 1){
                tempavg += j;
                tempn ++;
            }
        }
        if(tempn == 0){
            printf("-1\n");
            return 0;
        }
        tempavg /= tempn;
        avgst += tempavg;
    }
    printf("%lf\n", avgst);
    return 0;
}

void CH(int * n, int * ch, int chn){
    for(int i=0;i<chn;i++){
        n[ch[i]] = 0;
    }
}