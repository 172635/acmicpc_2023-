#include <stdio.h>
#include <stdlib.h>

typedef struct q{
    int wall;
    int i;
    int j;
    struct q * next;
}queue;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    char ** map = (char **)malloc(sizeof(char *) * n);
    int *** solve = (int ***)malloc(sizeof(int **) * 2);
    solve[0] = (int **)malloc(sizeof(int *) * n);
    solve[1] = (int **)malloc(sizeof(int *) * n);
    char str[1001];
    for(int i=0;i<n;i++){
        scanf("%s", str);
        map[i] = (char *)malloc(sizeof(char) * m);
        solve[0][i] = (int *)malloc(sizeof(int) * m);
        solve[1][i] = (int *)malloc(sizeof(int) * m);
        for(int j=0;j<m;j++){
            map[i][j] = str[j] - '0';
            solve[0][i][j] = 0;
            solve[1][i][j] = 0;
        }
    }
    queue * start = (queue *)malloc(sizeof(queue));
    queue * end = start;
    start->wall = 0;
    start->i = 0;
    start->j = 0;
    start->next = NULL;
    solve[0][0][0] = 1;
    while(start != NULL){
        queue * now = start;
        int nowcount = solve[now->wall][now->i][now->j];
        for(int d=0;d<4;d++){
            if(now->i + dy[d] < 0 || now->i + dy[d] >= n || now->j + dx[d] < 0 || now->j + dx[d] >= m){
                continue;
            }
            if(map[now->i+dy[d]][now->j+dx[d]] == 0){
                if(solve[now->wall][now->i+dy[d]][now->j+dx[d]] == 0){
                    solve[now->wall][now->i+dy[d]][now->j+dx[d]] = nowcount + 1;
                    queue * next = (queue *)malloc(sizeof(queue));
                    next->wall = now->wall;
                    next->i = now->i+dy[d];
                    next->j = now->j+dx[d];
                    next->next = NULL;
                    end->next = next;
                    end = next;
                }
            }else if(now->wall == 0){
                if(solve[1][now->i+dy[d]][now->j+dx[d]] == 0){
                    solve[1][now->i+dy[d]][now->j+dx[d]] = nowcount + 1;
                    queue * next = (queue *)malloc(sizeof(queue));
                    next->wall = 1;
                    next->i = now->i+dy[d];
                    next->j = now->j+dx[d];
                    next->next = NULL;
                    end->next = next;
                    end = next;
                }
            }
        }
        queue * del;
        del = start;
        start = start->next;
        free(del);
    }
    int pathcount = solve[0][n-1][m-1];
    if(solve[1][n-1][m-1] != 0){
        if(pathcount == 0){
            pathcount = solve[1][n-1][m-1];
        }else if(solve[1][n-1][m-1] < pathcount){
            pathcount = solve[1][n-1][m-1];
        }
    }
    if(pathcount == 0){
        printf("-1\n");
    }else{
        printf("%d\n", pathcount);
    }
    return 0;
}