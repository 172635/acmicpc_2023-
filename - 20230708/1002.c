#include <stdio.h>
#include <math.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int x1, y1, r1, x2, y2, r2;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        double r_sum = (double)(r1 + r2);
        double r_diff;
        if(r1 >= r2){
            r_diff = (double)(r1 - r2);
        }else{
            r_diff = (double)(r2 - r1);
        }
        double r = sqrt((double)((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
        
        if(r == 0.0 && r1 == r2){
            if(r1 == 0){
                printf("1\n");
            }else{
                printf("-1\n");
            }
        }else if(r == r_diff || r == r_sum){
            printf("1\n");
        }else if(r > r_diff && r < r_sum){
            printf("2\n");
        }else{
            printf("0\n");
        }
    }
    return 0;
}