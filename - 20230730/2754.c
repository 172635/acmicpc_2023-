#include <stdio.h>

int main(){
    char str[10];
    scanf("%s", str);
    float sc = 0.0;
    if(str[0] == 'A'){
        sc = 4.0;
    }else if(str[0] == 'B'){
        sc = 3.0;
    }else if(str[0] == 'C'){
        sc = 2.0;
    }else if(str[0] == 'D'){
        sc = 1.0;
    }else{
        printf("%.1f\n", sc);
        return 0;
    }
    if(str[1] == '+'){
        sc += 0.3;
    }else if(str[1] == '-'){
        sc -= 0.3;
    }
    printf("%.1f\n", sc);
    return 0;
}