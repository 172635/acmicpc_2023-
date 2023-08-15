#include <stdio.h>

int main(){
    long long int a = 0;
    long long int b = 0;
    char ch;
    while(1){
        ch = getchar();
        if(ch == '\0' || ch == '\n' || ch == ' '){
            break;
        }
        a += ch - 48;
    }
    while(1){
        ch = getchar();
        if(ch == '\0' || ch == '\n' || ch == ' '){
            break;
        }
        b += ch - 48;
    }
    printf("%lld\n", a * b);
    return 0;
}