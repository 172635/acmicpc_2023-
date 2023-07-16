// 오일러 피함수
// PI(n) = n * PI(1-1/p) = n/PI(p) * PI(p-1)

#include <stdio.h>
#include <math.h>

int main(){
    long long int n;
    scanf("%lld", &n);
    long long int pi1 = 1;
    long long int pi2 = 1;
    long long int nn = n;
    long long int c = 2;
    while(nn > 1){
        if(nn % c == 0){
            pi1 *= c;
            pi2 *= c-1;
            while(nn % c == 0){
                nn /= c;
            }
        }else{
            if(sqrt(nn) < c){
                c = nn;
            }else{
                c++;
            }
        }
    }
    printf("%lld\n", n / pi1 * pi2);
    return 0;
}