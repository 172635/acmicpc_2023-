#include <stdio.h>

int main(){
    char str[50];
    scanf("%s", str);
    int i = 0;
    int answer = 0;
    int temp = 0;
    int mode = 1;//1:plus/-1:minus
    while(mode != 0){
        switch(str[i]){
            case '+':
                answer += mode*temp;
                temp = 0;
                break;
            case '-':
                answer += mode*temp;
                temp = 0;
                mode = -1;
                break;
            case '\0':
                answer += mode*temp;
                mode = 0;
                break;
            default:
                temp = temp * 10 + str[i] - 48;
                break;
        }
        i++;
    }
    printf("%d", answer);
    return 0;
}