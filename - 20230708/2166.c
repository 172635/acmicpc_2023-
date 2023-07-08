#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int CCW(int, int, int, int, int, int);
double AR(int, int, int, int, int, int);

int main(){
    int n;
    scanf("%d", &n);
    int ** xy = (int **)malloc(sizeof(int*) * n);
    int line = 0;
    for(int i=0;i<n;i++){
        xy[i] = (int *)malloc(sizeof(int) * 2);
        scanf("%d %d", &xy[i - line][0], &xy[i - line][1]);
        if(i>1 && CCW(xy[i - line - 2][0], xy[i - line - 2][1], xy[i - line - 1][0], xy[i - line - 1][1], xy[i - line][0], xy[i - line][1]) == 0){
            xy[i - line - 1][0] = xy[i - line][0];
            xy[i - line - 1][1] = xy[i - line][1];
            line ++;
        }
    }
    int wise = CCW(xy[0][0], xy[0][1], xy[1][0], xy[1][1], xy[2][0], xy[2][1]);
    double area = 0.0;
    for(int i=1;i<n-line-1;i++){
        double nwar = AR(xy[0][0], xy[0][1], xy[i][0], xy[i][1], xy[i+1][0], xy[i+1][1]);
        nwar *= (wise * CCW(xy[0][0], xy[0][1], xy[i][0], xy[i][1], xy[i+1][0], xy[i+1][1]));

        area += nwar;
    }
    if(area < 0){
        area = - area;
    }
    printf("%.1f\n", area);
    return 0;
}

int CCW(int x1, int y1, int x2, int y2, int x3, int y3){
    long long int r = (long long int)(x2 - x1) * (y3 - y1) - (long long int)(x3 - x1) * (y2 - y1);
    if(r < 0){
        return -1;
    }else if(r == 0){
        return 0;
    }else{
        return 1;
    }
}

double AR(int x1, int y1, int x2, int y2, int x3, int y3){
    double r1 = (double)(x1) * y2 + (double)(x2) * y3 + (double)(x3) * y1;
    double r2 = (double)(x2) * y1 + (double)(x3) * y2 + (double)(x1) * y3;
    double r = (r1 - r2) / 2;
    if(r < 0){
        r = -r;
    }
    return r;
}