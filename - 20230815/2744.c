#include <stdio.h>

int main(){
    char st[101];
    scanf("%s", st);
    for(int i=0;st[i] != '\0'; i++){
        if(st[i] >= 'A' && st[i] <= 'Z'){
            printf("%c", st[i] + 'a' - 'A');
        }else{
            printf("%c", st[i] + 'A' - 'a');
        }
    }
    printf("\n");
    return 0;
}