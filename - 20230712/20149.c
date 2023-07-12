#include <stdio.h>

void crossP(int *, int);
int cross(int *);
int CCW(int,int,int,int,int,int);

int main(){
    int xy[8];
    for(int i=0;i<8;i++){
        scanf("%d", &xy[i]);
    }
    int x = cross(xy);
    if(x == 0){
        printf("0\n");
    }else if(x == 3){
        printf("1\n");
    }else{
        printf("1\n");
        crossP(xy, x);
    }
    return 0;
}

void crossP(int *xy, int c){
    if(c == 2){
        if((xy[1] == xy[5] && xy[0] == xy[4]) || (xy[1] == xy[7] && xy[0] == xy[6])){
            printf("%d %d\n", xy[0], xy[1]);
        }else{
            printf("%d %d\n", xy[2], xy[3]);
        }
        return;
    }
    int temp;
    if(xy[0] > xy[2]){
        temp = xy[2];
        xy[2] = xy[0];
        xy[0] = temp;
        temp = xy[3];
        xy[3] = xy[1];
        xy[1] = temp;
    }
    if(xy[4] > xy[6]){
        temp = xy[6];
        xy[6] = xy[4];
        xy[4] = temp;
        temp = xy[7];
        xy[7] = xy[5];
        xy[5] = temp;
    }
    if(xy[0] == xy[2] || xy[4] == xy[6]){
        if(xy[4] == xy[6]){
            temp = xy[4];
            xy[4] = xy[0];
            xy[0] = temp;
            temp = xy[5];
            xy[5] = xy[1];
            xy[1] = temp;
            temp = xy[6];
            xy[6] = xy[2];
            xy[2] = temp;
            temp = xy[7];
            xy[7] = xy[3];
            xy[3] = temp;
        }
        double xd = (double)(xy[0] - xy[4]);
        double tang = (double)(xy[7] - xy[5]) / (xy[6] - xy[4]);
        double yc = xd * tang + xy[5];
        printf("%.9f %.9f\n", (double)(xy[0]), yc);
    }else{
        if(xy[0] > xy[4]){
            temp = xy[4];
            xy[4] = xy[0];
            xy[0] = temp;
            temp = xy[5];
            xy[5] = xy[1];
            xy[1] = temp;
            temp = xy[6];
            xy[6] = xy[2];
            xy[2] = temp;
            temp = xy[7];
            xy[7] = xy[3];
            xy[3] = temp;
        }
        double tang1 = (double)(xy[3] - xy[1]) / (xy[2] - xy[0]);
        double tang2 = (double)(xy[7] - xy[5]) / (xy[6] - xy[4]);
        double y0 = xy[1] + tang1 * (xy[4] - xy[0]);
        double yd = xy[5] - y0;
        double xmore = yd / (tang1 - tang2);
        printf("%.9f %.9f\n", xy[4] + xmore, xy[5] + xmore * tang2);
    }
    return;
}

int cross(int * xy){
    int ccw1 = CCW(xy[0], xy[1], xy[2], xy[3], xy[4], xy[5]);
    int ccw2 = CCW(xy[0], xy[1], xy[2], xy[3], xy[6], xy[7]);
    int cc1 = ccw1 * ccw2;
    int ccw3 = CCW(xy[4], xy[5], xy[6], xy[7], xy[0], xy[1]);
    int ccw4 = CCW(xy[4], xy[5], xy[6], xy[7], xy[2], xy[3]);
    int cc2 = ccw3 * ccw4;
    if(cc1 == 0 && cc2 == 0){
        if(xy[0] == xy[2]){
            int temp;
            if(xy[1] > xy[3]){
                temp = xy[3];
                xy[3] = xy[1];
                xy[1] = temp;
            }
            if(xy[5] > xy[7]){
                temp = xy[7];
                xy[7] = xy[5];
                xy[5] = temp;
            }
            if((xy[1] <= xy[7]) && (xy[5] <= xy[3])){
                if(ccw1 == 0 && ccw2 == 0 && ccw3 == 0 && ccw4 == 0){
                    if(xy[1] == xy[7] || xy[3] == xy[5]){ // 한 점 겹치는 경우(평행)
                        return 2;
                    }else{
                        return 3;
                    }
                }else{ // 한 점 겹치는 경우(평행 x)
                    return 1;
                }
            }else{
                return 0;
            }
        }else{
            int temp;
            if(xy[0] > xy[2]){
                temp = xy[2];
                xy[2] = xy[0];
                xy[0] = temp;
                temp = xy[3];
                xy[3] = xy[1];
                xy[1] = temp;
            }
            if(xy[4] > xy[6]){
                temp = xy[6];
                xy[6] = xy[4];
                xy[4] = temp;
                temp = xy[7];
                xy[7] = xy[5];
                xy[5] = temp;
            }
            if((xy[0] <= xy[6]) && (xy[4] <= xy[2])){
                if(ccw1 == 0 && ccw2 == 0 && ccw3 == 0 && ccw4 == 0){
                    if((xy[1] == xy[7] && xy[0] == xy[6]) || (xy[3] == xy[5] && xy[2] == xy[4])){ // 한 점 겹치는 경우(평행)
                        return 2;
                    }else{
                        return 3;
                    }
                }else{ // 한 점 겹치는 경우(평행 x)
                    return 1;
                }
            }else{
                return 0;
            }
        }
    }else{
        return (cc1 <= 0) && (cc2 <= 0);
    }
}

int CCW(int x1, int y1, int x2, int y2, int x3, int y3){
    long long int ccw = ((long long int)(x2 - x1))*(y3 - y1) - ((long long int)(x3 - x1))*(y2 - y1);
    if(ccw > 0){
        return 1;
    }else if(ccw == 0){
        return 0;
    }else{
        return -1;
    }
}