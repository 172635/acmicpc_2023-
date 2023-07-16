#include <stdio.h>

int main(){
    while(1){
        int count = 0;

        char ch;
        ch = getchar();
        if(ch == '#'){
            break;
        }
        while(ch != '\n'){
            switch(ch){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                count ++;
                break;
            default:
                break;
            }
            ch = getchar();
        }
        printf("%d\n", count);
    }
    return 0;
}