#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, s;
    scanf("%d %d", &n, &s);
    int * ar = (int *)malloc(sizeof(int) * n);
    int sum = 0;
    for(int i=0;i<n;i++){
        scanf("%d", &ar[i]);
        sum += ar[i];
    }
    if(sum < s){
        printf("0\n");
        return 0;
    }

    int first = 0;
    int last = 0;
    sum = ar[0];
    int minL = n;
    while(first < n){
        if(last < first){
            last = first;
            sum = ar[first];
            continue;
        }
        if(sum >= s){
            if(minL > last - first + 1){
                minL = last - first + 1;
            }
            sum -= ar[first];
            first ++;
            continue;
        }
        if(last == n-1){
            first ++;
            continue;
        }
        last ++;
        sum += ar[last];
    }
    printf("%d\n", minL);
    return 0;
}