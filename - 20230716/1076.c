#include <stdio.h>

int main(){
    int n = 0;
    char str[20];
    for(int i=0;i<3;i++){
        scanf("%s", str);
        int x;
        if(str[0] == 'b'){
            if(str[1] == 'l'){
                if(str[2] == 'a'){
                    x = 0;
                }else{
                    x = 6;
                }
            }else{
                x = 1;
            }
        }else if(str[0] == 'r'){
            x = 2;
        }else if(str[0] == 'o'){
            x = 3;
        }else if(str[0] == 'y'){
            x = 4;
        }else if(str[0] == 'g'){
            if(str[3] == 'e'){
                x = 5;
            }else{
                x = 8;
            }
        }else if(str[0] == 'v'){
            x = 7;
        }else{
            x = 9;
        }
        if(i < 2){
            n *= 10;
            n += x;
        }else{
            if(n == 0){
                printf("0\n");
            }else{
                printf("%d", n);
                for(int j=0;j<x;j++){
                    printf("0");
                }
                printf("\n");
            }
        }
    }
    return 0;
}