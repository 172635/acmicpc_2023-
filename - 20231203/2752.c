#include <stdio.h>

int main(){
    int a[3];
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    for(int i=0;i<3;i++){
        int min = i;
        for(int j=i+1;j<3;j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    printf("%d %d %d\n", a[0], a[1], a[2]);
    return 0;
}