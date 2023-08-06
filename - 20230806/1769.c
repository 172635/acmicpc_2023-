#include <stdio.h>

int main(){
    int len = 0;
    int n = 0;
    int count = 0;
    char ch;
    for(len = 0; ; len ++){
        ch = getchar();
        if(ch == '\n' || ch == '\0'){
            break;
        }
        n += (ch - '0');
    }
    if(len > 1){
        count = 1;
    }
    while(n >= 10){
        int m = 0;
        while(n > 0){
            m += n % 10;
            n /= 10;
        }
        n = m;
        count ++;
    }
    printf("%d\n", count);
    if(n == 3 || n == 6 || n == 9){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}