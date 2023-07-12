#include <stdio.h>

int cost(int, int);

int main(){
    int prev = 0;
    int prevP[5] = {0, -1, -1, -1, -1};
    while(1){
        int n;
        scanf("%d", &n);
        if(n == 0){
            break;
        }
        int newP[5];
        newP[0] = prevP[0] + cost(prev, n);
        for(int i=1;i<=4;i++){
            if(i == n){
                newP[i] = -1;
            }
            newP[i] = 400000;
            int tempmin;
            if(prev == i){
                for(int j=0;j<5;j++){
                    if(prevP[j] == -1){
                        continue;
                    }
                    tempmin = prevP[j] + cost(j, n);
                    if(tempmin < newP[i]){
                        newP[i] = tempmin;
                    }
                }
            }else if(prevP[i] == -1){
                newP[i] = -1;
            }else{
                newP[i] = prevP[i] + cost(prev, n);
            }
        }
        prev = n;
        for(int i=0;i<5;i++){
            prevP[i] = newP[i];
        }
    }
    int minF = 400000;
    for(int i=0;i<5;i++){
        if(prevP[i] != -1 && prevP[i] < minF){
            minF = prevP[i];
        }
    }
    printf("%d\n", minF);
    return 0;
}

int cost(int from, int to){
    if(from == 0){
        return 2;
    }
    if(from == to){
        return 1;
    }
    if(from - to == 1 || to - from == 1 || from - to == 3 || to - from == 3){
        return 3;
    }
    if(from - to == 2 || to - from == 2){
        return 4;
    }
    return -1;
}