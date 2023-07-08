#include <stdio.h>

int checkStr(char *);

int main(){
    while(1){
        char str[101];
        for(int i=0;i<101;i++){
            char ch = getchar();
            str[i] = ch;
            if(ch == '.'){
                str[i] = '\0';
            }else if(ch == '\n'){
                break;
            }
        }
        if(str[0] == '\0'){
            break;
        }
        if(checkStr(str) == 1){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }
    return 0;
}

int checkStr(char * str){
    //'\0'확인
    if(str[0] == '\0'){
        return 1;
    }
    //개수 확인
    int sqb = 0;
    int b = 0;
    for(int i=0;str[i] != '\0';i++){
        if(str[i] == '('){
            b ++;
        }else if(str[i] == ')'){
            if(b <= 0){
                return 0;
            }
            b --;
        }else if(str[i] == '['){
            sqb ++;
        }else if(str[i] == ']'){
            if(sqb <= 0){
                return 0;
            }
            sqb --;
        }
    }
    if(sqb != 0 || b != 0){
        return 0;
    }

    //개수 맞다면, 괄호 내부 재확인
    int bLoc = 0;
    int sqbLoc = 0;
    for(int i=0;str[i] != '\0';i++){
        if(str[i] == '('){
            bLoc = i;
            sqbLoc = -1;
            break;
        }else if(str[i] == '['){
            sqbLoc = i;
            bLoc = -1;
            break;
        }
    }
    if(bLoc != -1 && sqbLoc != -1){
        return 1;
    }
    for(int i=0;str[i] != '\0';i++){
        if(bLoc == -1){
            if(str[i] == '['){
                sqb ++;
            }else if(str[i] == ']'){
                sqb --;
                if(sqb == 0){
                    str[i] = '\0';
                    return checkStr(str + sqbLoc + 1) + checkStr(str + i + 1) == 2;
                }
            }
        }else if(sqbLoc == -1){
            if(str[i] == '('){
                b ++;
            }else if(str[i] == ')'){
                b --;
                if(b == 0){
                    str[i] = '\0';
                    return checkStr(str + bLoc + 1) + checkStr(str + i + 1) == 2;
                }
            }
        }
    }
    return 0;
}