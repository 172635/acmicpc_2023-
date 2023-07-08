#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int num[8001];
    for(int i=0;i<8001;i++){
        num[i] = 0;
    }
    double avg = 0.0;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d", &x);
        num[x+4000] ++;
        avg += x;
    }
    avg /= n;
    if(avg < 0){
        avg = - avg;
        if(avg - (int)avg < 0.5){
            if((int)avg == 0){
                printf("0\n");
            }else{
                printf("-%d\n", (int)avg);
            }
        }else{
            printf("-%d\n", (int)avg+1);
        }
    }else{
        if(avg - (int)avg < 0.5){
            printf("%d\n", (int)avg);
        }else{
            printf("%d\n", (int)avg+1);
        }
    }
    int min = -1, max = -1, sum = 0;
    int mid = -1;
    int k = -1;
    int k_check = 1;
    for(int i=0;i<8001;i++){
        if(num[i] != 0){
            if(min == -1){
                min = i;
            }
            max = i;
            sum += num[i];
            if(sum > n/2 && mid == -1){
                mid = i;
            }
            if(k == -1){
                k = i;
            }else if(num[k] < num[i]){
                k = i;
                k_check = 1;
            }else if(num[k] == num[i]){
                if(k_check == 1){
                    k_check = 2;
                    k = i;
                }
            }
        }
    }
    printf("%d\n%d\n%d\n", mid - 4000, k - 4000, max-min);
    return 0;
}