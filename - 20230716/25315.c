#include <stdio.h>
#include <stdlib.h>

typedef struct linklist{
    int index;
    struct linklist * next;
}ll;

int checkcross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

int main(){
    int n;
    scanf("%d", &n);

    int ** line = (int **)malloc(sizeof(int*)*n);
    ll * wline = (ll *)malloc(sizeof(ll));

    int * check = (int *)malloc(sizeof(int)*n);
    int * crossnum = (int *)malloc(sizeof(int)*n);
    ll ** cross = (ll **)malloc(sizeof(ll *)*n);
    ll ** tempcross = (ll **)malloc(sizeof(ll *)*n);

    for(int i=0;i<n;i++){
        int sx, sy, ex, ey, wi;
        scanf("%d %d %d %d %d", &sx, &sy, &ex, &ey, &wi);
        line[i] = (int *)malloc(sizeof(int)*5);
        line[i][0] = sx;
        line[i][1] = sy;
        line[i][2] = ex;
        line[i][3] = ey;
        line[i][4] = wi;
        ll * set = wline;
        for(int j=0;j<=i;j++){
            if(j == i){
                ll * now = (ll *)malloc(sizeof(ll));
                now->index = i;
                set->next = now;
                break;
            }else if(line[set->next->index][4] > wi){
                ll * now = (ll *)malloc(sizeof(ll));
                now->index = i;
                now->next = set->next;
                set->next = now;
                break;
            }
            set = set->next;
        }

        check[i] = 0;
        crossnum[i] = 0;
        cross[i] = (ll *)malloc(sizeof(ll));
        cross[i]->index = -1;
        cross[i]->next = NULL;
        tempcross[i] = cross[i];
    }
    
    //교차 계산. n개 겹친다면 n개 리스트 만들고. check 확인.
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(checkcross(line[i][0], line[i][1], line[i][2], line[i][3], line[j][0], line[j][1], line[j][2], line[j][3])){
                ll * now = (ll *)malloc(sizeof(ll));
                now->index = j;
                now->next = NULL;
                tempcross[i] -> next = now;
                tempcross[i] = now;
                crossnum[i] ++;

                ll * now2 = (ll *)malloc(sizeof(ll));
                now2->index = i;
                now2->next = NULL;
                tempcross[j] -> next = now2;
                tempcross[j] = now2;
                crossnum[j] ++;
            }
        }
    }

    long long int Sum = 0;
    for(int i=0;i<n;i++){
        wline = wline->next;
        int index = wline->index;
        Sum += ((long long int)line[index][4]) * (crossnum[index] + 1);
        check[index] = 1;
        while(cross[index]->next != NULL){
            cross[index] = cross[index]->next;
            if(check[cross[index]->index] == 0){
                crossnum[cross[index]->index] --;
            }
        }
    }
    printf("%lld\n", Sum);
}

int checkcross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    int ccw1 = (((long long int)(x2 - x1))*(y3 - y1) - ((long long int)(x3 - x1))*(y2 - y1) > 0);
    int ccw2 = (((long long int)(x2 - x1))*(y4 - y1) - ((long long int)(x4 - x1))*(y2 - y1) > 0);
    int cc1 = ((ccw1 + ccw2) == 1);
    int ccw3 = (((long long int)(x4 - x3))*(y1 - y3) - ((long long int)(x1 - x3))*(y4 - y3) > 0);
    int ccw4 = (((long long int)(x4 - x3))*(y2 - y3) - ((long long int)(x2 - x3))*(y4 - y3) > 0);
    int cc2 = ((ccw3 + ccw4) == 1);

    return (cc1 == 1 && cc2 == 1);
}