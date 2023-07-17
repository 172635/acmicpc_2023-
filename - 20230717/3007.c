#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int * add = (int *)malloc(sizeof(int) * n);
    add[0] = 0;
    add[1] = 0;
    add[2] = 0;
    int * two = (int *)malloc(sizeof(int) * n);
    for(int i=0;i<n;i++){
        scanf("%d", &two[i]);
        if(i > 1 && i < n-1){
            int diff = two[i] - two[i-1];
            add[i+1] = add[i-2] + diff;
        }
    }
    int a, b, c;
    int first = two[0];
    int second = two[1];
    int last = two[n-1];
    int A, B, C;
    if(n%3 == 1){
        A = add[n-1];
        B = add[n-3];
        C = add[n-2];
        a = (int)((((long long int)first) - second + last - 2 * A - C)/3);
        b = (int)((((long long int)first) + second - last + C - a)/2);
        c = b - first + last - C;
    }else if(n%3 == 2){
        A = add[n-2];
        B = add[n-1];
        C = add[n-3];
        a = (int)((2 * ((long long int)last) - first - 2 * A - B)/3);
        b = (int)(((long long int)last) - A - B - 2* a);
        c = second - a - b;
    }else{
        A = 0;
        B = 0;
        C = 0;
        for(int i=3;i<n;i++){
            if(i%3 == 0){
                if(A > add[i]){
                    A = add[i];
                }
            }else if(i%3 == 1){
                if(B > add[i]){
                    B = add[i];
                }
            }else{
                if(C > add[i]){
                    C = add[i];
                }
            }
        }
        a = -A + 1;
        b = -B + 1;
        c = second - a - b;
    }
    printf("%d\n%d\n%d\n", a, b, c);
    for(int i=3;i<n;i++){
        if(i%3 == 0){
            printf("%d\n", a + add[i]);
        }else if(i%3 == 1){
            printf("%d\n", b + add[i]);
        }else{
            printf("%d\n", c + add[i]);
        }
    }
    return 0;
}