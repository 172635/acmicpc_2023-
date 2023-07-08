#include <stdio.h>
#include <stdlib.h>

typedef struct _{
    int value;
    struct _ * next;
}queue;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int person[51][52];
    int party[51][52];
    queue * del;
    queue * first = (queue *)malloc(sizeof(queue));
    first->next = NULL;
    queue * last = first;
    int canParty = 0;
    for(int i=1;i<=n;i++){
        person[i][0] = 0; //false
        person[i][1] = 0; //party num
    }
    for(int i=1;i<=m;i++){
        party[i][0] = 0; //false
    }
    int tn;
    scanf("%d", &tn);
    for(int i=0;i<tn;i++){
        int x;
        scanf("%d", &x);
        person[x][0] = 1;
    }
    for(int i=0;i<m;i++){
        scanf("%d", &party[i][1]);
        for(int j=2;j<party[i][1]+2;j++){
            scanf("%d", &party[i][j]);
            person[party[i][j]][1] ++;
            person[party[i][j]][person[party[i][j]][1] + 1] = i;
            if(person[party[i][j]][0] == 1){
                if(party[i][0] == 0){
                    queue * now = (queue *)malloc(sizeof(queue));
                    now->value = i;
                    now->next = NULL;
                    last->next = now;
                    last = now;
                    party[i][0] = 1;
                }
            }
        }
    }
    del = first;
    first = first->next;
    free(del);
    while(first != NULL){
        int nowparty = first->value;
        for(int i=2;i<party[nowparty][1]+2;i++){
            int pe = party[nowparty][i];
            if(person[pe][0] == 0){
                person[pe][0] = 1;
                int pepnum = person[pe][1];
                for(int j=2;j<2+pepnum;j++){
                    int pa = person[pe][j];
                    if(party[pa][0] == 0){
                        queue * now = (queue *)malloc(sizeof(queue));
                        now->value = pa;
                        now->next = NULL;
                        last->next = now;
                        last = now;
                        party[pa][0] = 1;
                    }
                }
            }
        }
        del = first;
        first = first->next;
        free(del);
    }
    for(int i=0;i<m;i++){
        if(party[i][0] == 0){
            canParty ++;
        }
    }
    printf("%d\n", canParty);
    return 0;
}