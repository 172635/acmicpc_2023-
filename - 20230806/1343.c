#include <stdio.h>

int main(){
    char board[51];
    scanf("%s", board);
    char nb[51];
    int check = 0;
    int index = 0;
    int n = 0;
    while(1){
        if(board[index] == 'X'){
            n ++;
            if(n == 4){
                nb[index-3] = 'A';
                nb[index-2] = 'A';
                nb[index-1] = 'A';
                nb[index] = 'A';
                n = 0;
            }
        }else if(board[index] == '.'){
            if(n == 1 || n == 3){
                check = 1;
                printf("-1\n");
                break;
            }else if(n == 2){
                nb[index-2] = 'B';
                nb[index-1] = 'B';
                n = 0;
            }
            nb[index] = '.';
        }else if(board[index] == '\0'){
            if(n == 1 || n == 3){
                check = 1;
                printf("-1\n");
                break;
            }else if(n == 2){
                nb[index-2] = 'B';
                nb[index-1] = 'B';
                n = 0;
            }
            nb[index] = '\0';
            break;
        }
        index ++;
    }
    if(check == 0){
        printf("%s\n", nb);
    }
    return 0;
}