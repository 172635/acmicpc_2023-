#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[100];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    if(n == 1){
        printf("A\n");
        return 0;
    }else if(n == 2){
        if(arr[0] == arr[1]){
            printf("%d\n", arr[0]);
            return 0;
        }else{
            printf("A\n");
            return 0;
        }
    }
    int a, b;
    int r21 = arr[2] - arr[1];
    int r10 = arr[1] - arr[0];
    if(r10 != 0){
        if(r21 % r10 != 0){
            printf("B\n");
            return 0;
        }
        a = r21 / r10;
    }else{
        if(r21 != 0){
            printf("B\n");
            return 0;
        }
        a = 0;
    }
    b = arr[1] - arr[0] * a;
    for(int i=3;i<n;i++){
        if(arr[i] != arr[i-1] * a + b){
            printf("B\n");
            return 0;
        }
    }
    printf("%d\n", arr[n-1]*a+b);
    return 0;
}