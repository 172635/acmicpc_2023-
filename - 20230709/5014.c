#include <stdio.h>
#include <stdlib.h>

int main(){
    int f, s, g, u, d;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
    int button = 0;
    char * check = (char *)malloc(sizeof(char)*f);
    for(int i=1;i<=f;i++){
        check[i] = 0;
    }
    while(s != g){
        if(s <= 0 || s > f || check[s] == 1){
            printf("use the stairs\n");
            return 0;
        }
        check[s] = 1;
        if(s <= d){
            s = s+u;
        }else if(s > f - u){
            s = s-d;
        }else if(s < g){
            s = s+u;
        }else{
            s = s-d;
        }
        button ++;
    }
    printf("%d\n", button);
    return 0;
}