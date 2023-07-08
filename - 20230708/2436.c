#include <stdio.h>
#include <math.h>

int main(){
    int minN, maxN;
    scanf("%d %d", &minN, &maxN);
    int mm = maxN / minN;
    int minP[2];
    minP[0] = 1;
    minP[1] = mm;
    int nowP[2];
    for(int i=2;i<=sqrt(mm);i++){
        if(mm % i == 0){
            int check = 0;
            for(int j=2;j<=sqrt(mm/i);j++){
                if(mm/i % j == 0){
                    if(i % j == 0 || i % (mm/i/j) == 0){
                        check = 1;
                        break;
                    }
                }
            }
            if(i % (mm/i) == 0){
                check = 1;
            }
            if(check == 0){
                if(minP[0] + minP[1] > i + mm / i){
                    minP[0] = i;
                    minP[1] = mm / i;
                }
            }
        }
    }
    printf("%d %d\n", minP[0] * minN, minP[1] * minN);
    return 0;
}