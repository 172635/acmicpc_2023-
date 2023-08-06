#include <stdio.h>
#include <stdlib.h>

char ** video;

char * search(int sx, int sy, int size);

int main(){
    int n;
    scanf("%d", &n);
    video = (char **)malloc(sizeof(char *)*n);
    for(int i=0;i<n;i++){
        video[i] = (char *)malloc(sizeof(char) * (n+1));
        scanf("%s", video[i]);
    }
    char * st = search(0, 0, n);
    printf("%s", st);
}

char * search(int sx, int sy, int size){
    if(size == 1){
        char * ne = (char *)malloc(sizeof(char) * 10);
        ne[0] = video[sy][sx];
        ne[1] = '\0';
        return ne;
    }
    char * a1 = search(sx, sy, size/2);
    char * a2 = search(sx+size/2, sy, size/2);
    char * a3 = search(sx, sy+size/2, size/2);
    char * a4 = search(sx+size/2, sy+size/2, size/2);
    if(a1[0] != '(' && a2[0] != '(' && a3[0] != '(' && a4[0] != '(' && a1[0] == a2[0] && a2[0] == a3[0] && a3[0] == a4[0]){
        char * ne = (char *)malloc(sizeof(char) * 10);
        ne[0] = a1[0];
        ne[1] = '\0';
        free(a1);
        free(a2);
        free(a3);
        free(a4);
        return ne;
    }else{
        char * ne = (char *)malloc(sizeof(char) * (size*size*2));
        int index = 0;
        ne[index] = '(';
        index ++;
        for(int i=0;;i++){
            if(a1[i] == '\0'){
                index += i;
                break;
            }
            ne[index+i] = a1[i];
        }
        for(int i=0;;i++){
            if(a2[i] == '\0'){
                index += i;
                break;
            }
            ne[index+i] = a2[i];
        }
        for(int i=0;;i++){
            if(a3[i] == '\0'){
                index += i;
                break;
            }
            ne[index+i] = a3[i];
        }
        for(int i=0;;i++){
            if(a4[i] == '\0'){
                index += i;
                break;
            }
            ne[index+i] = a4[i];
        }
        ne[index] = ')';
        index ++;
        ne[index] = '\0';
        free(a1);
        free(a2);
        free(a3);
        free(a4);
        return ne;
    }
}