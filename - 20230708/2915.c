#include <stdio.h>

int main(){
    char str[10];
    scanf("%s", str);
    int num[5]; //i, v, x, l, c
    for(int i=0;i<5;i++){
        num[i] = 0;
    }
    for(int i=0;str[i]!='\0';i++){
        switch(str[i]){
        case 'I':
            num[0] ++;
            break;
        case 'V':
            num[1] ++;
            break;
        case 'X':
            num[2] ++;
            break;
        case 'L':
            num[3] ++;
            break;
        case 'C':
            num[4] ++;
            break;
        default:
            break;
        }
    }
    int print = 0;
    if(num[3] != 0 || num[4] != 0){
        if(num[2] == 1){
            print -= 10;
            num[2] = 0;
        }else if(num[2] == 2){
            if(num[0] == 1 && num[1] == 0){
                print -= 10;
                num[2] = 1;
            }
        }
    }
    if(num[0] == 1){
        if(num[1] != 0 || num[2] != 0){
            print --;
            num[0] = 0;
        }
    }
    print += num[0] + num[1] * 5 + num[2] * 10 + num[3] * 50 + num[4] * 100;
    if(print / 10 == 9){
        printf("XC");
    }else if(print / 10 == 4){
        printf("XL");
    }else{
        if(print / 10 >= 5){
            printf("L");
        }
        for(int i=0;i<(print%50)/10;i++){
            printf("X");
        }
    }
    if(print % 10 == 9){
        printf("IX");
    }else if(print % 10 == 4){
        printf("IV");
    }else{
        if(print % 10 >= 5){
            printf("V");
        }
        for(int i=0;i<print%5;i++){
            printf("I");
        }
    }
    printf("\n");
    return 0;
}