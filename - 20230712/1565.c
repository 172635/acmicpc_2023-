#include <stdio.h>
#include <math.h>

int gcd(int,int);

int main(){
    int d, m;
    scanf("%d %d", &d, &m);
    int dN[50], mN[50];
    int prevD = 1;
    int nowD;
    int check = 0;
    for(int i=0;i<d;i++){
        scanf("%d", &nowD);
        long long int d = (long long int)prevD * nowD / gcd(prevD, nowD);
        if(d > 1000000000){
            prevD = 1;
            check = 1;
        }else{
            prevD = d;
        }
    }
    int prevM = 1;
    int nowM;
    for(int i=0;i<m;i++){
        scanf("%d", &nowM);
        if(i > 0){
            int m = gcd(prevM, nowM);
            prevM = m;
        }else{
            prevM = nowM;
        }
    }
    if(check == 1 || prevM % prevD != 0){
        printf("0\n");
        return 0;
    }
    int mmN = prevM / prevD;
    int c = 2;
    int cnum = 0;
    int num = 1;
    while(1){
        if(mmN % c == 0){
            cnum ++;
            mmN /= c;
        }else{
            if(sqrt(mmN) < c){
                c = mmN;
            }else{
                c++;
            }
            num *= (cnum+1);
            cnum = 0;
            if(mmN == 1){
                break;
            }
        }
    }
    printf("%d\n", num);
}

int gcd(int a, int b){
    if(a < b){
        int temp = b;
        b = a;
        a = temp;
    }
    if(a % b == 0){
        return b;
    }else{
        return gcd(b, a%b);
    }
}