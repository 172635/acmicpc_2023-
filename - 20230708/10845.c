#include <stdio.h>
#include <stdlib.h>

typedef struct q{
    int value;
    struct q * next;
}queue;

int main(){
    int n;
    scanf("%d", &n);
    queue * first = (queue *)malloc(sizeof(queue));
    first->next = NULL;
    queue * last = first;
    queue * del;
    int len = 0;
    char cmd[20];
    for(int i=0;i<n;i++){
        scanf("%s", cmd);
        if(cmd[0] == 'p' && cmd[1] == 'u'){ //push
            int num;
            scanf("%d", &num);
            queue * pushQ = (queue *)malloc(sizeof(queue));
            pushQ->value = num;
            pushQ->next = NULL;
            last->next = pushQ;
            last = pushQ;
            len ++;
        }else if(cmd[0] == 'p'){ //pop
            if(len == 0){
                printf("-1\n");
            }else{
                printf("%d\n", first->next->value);
                del = first->next;
                first->next = first->next->next;
                free(del);
                len --;
                if(len == 0){
                    last = first;
                }
            }
        }else if(cmd[0] == 's'){ //size
            printf("%d\n", len);
        }else if(cmd[0] == 'e'){ //empty
            printf("%d\n", len == 0);
        }else if(cmd[0] == 'f'){ //front
            if(len == 0){
                printf("-1\n");
            }else{
                printf("%d\n", first->next->value);
            }
        }else{ //back
            if(len == 0){
                printf("-1\n");
            }else{
                printf("%d\n", last->value);
            }
        }
    }
    return 0;
}