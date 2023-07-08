#include <stdio.h>
#include <math.h>

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int n;
        scanf("%d", &n);
        int sum = 0;
        for(int j=0;j<n;j++){
            int cx, cy, cr;
            scanf("%d %d %d", &cx, &cy, &cr);
            double dis1 = sqrt((x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy));
            double dis2 = sqrt((x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy));
            if((dis1 < cr) + (dis2 < cr) == 1){
                sum ++;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}