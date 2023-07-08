#include <stdio.h>

int cross(int *);
int CCW(int,int,int,int,int,int);

int main(){
    int xy[8];
    for(int i=0;i<8;i++){
        scanf("%d", &xy[i]);
    }
    printf("%d\n", cross(xy));
    return 0;
}

int cross(int * xy){
    int ccw1 = CCW(xy[0], xy[1], xy[2], xy[3], xy[4], xy[5]);
    int ccw2 = CCW(xy[0], xy[1], xy[2], xy[3], xy[6], xy[7]);
    int cc1 = ccw1 * ccw2;
    int ccw3 = CCW(xy[4], xy[5], xy[6], xy[7], xy[0], xy[1]);
    int ccw4 = CCW(xy[4], xy[5], xy[6], xy[7], xy[2], xy[3]);
    int cc2 = ccw3 * ccw4;
    return (cc1 < 0) && (cc2 < 0);
}

int CCW(int x1, int y1, int x2, int y2, int x3, int y3){
    long long int ccw = ((long long int)(x2 - x1))*(y3 - y1) - ((long long int)(x3 - x1))*(y2 - y1);
    if(ccw > 0){
        return 1;
    }else{
        return -1;
    }
}