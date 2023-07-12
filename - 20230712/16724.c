#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    char ch;
    scanf("%c", &ch);
    int * parent = (int *)malloc(sizeof(int)*n*m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ch = getchar();
            if(ch == 'D'){
                if(i == n-1){
                    parent[i*m+j] = i*m+j;
                }else{
                    parent[i*m+j] = i*m+j + m;
                }
            }else if(ch == 'U'){
                if(i == 0){
                    parent[i*m+j] = i*m+j;
                }else{
                    parent[i*m+j] = i*m+j - m;
                }
            }else if(ch == 'L'){
                if(j == 0){
                    parent[i*m+j] = i*m+j;
                }else{
                    parent[i*m+j] = i*m+j-1;
                }
            }else{
                if(j == m-1){
                    parent[i*m+j] = i*m+j;
                }else{
                    parent[i*m+j] = i*m+j+1;
                }
            }
        }
        scanf("%c", &ch);
    }
    int * check = (int *)malloc(sizeof(int)*n*m);
    for(int i=0;i<n*m;i++){
        check[i] = 0;
    }
    for(int i=0;i<n*m;i++){
        //check
        if(i == parent[i] || check[i] == 1){
            continue;
        }
        check[i] = 1;
        //parent
        int p = parent[i];
        while(1){
            if(p == i){
                parent[i] = i;
                break;
            }else if(p == parent[p]){
                parent[i] = p;
                break;
            }
            check[p] = 1;
            int pt = parent[p];
            parent[p] = i;
            p = pt;
        }
    }
    int sum = 0;
    for(int i=0;i<n*m;i++){
        if(parent[i] == i){
            sum ++;
        }
    }
    printf("%d\n", sum);
    return 0;
}