#include <stdio.h>
#include <stdlib.h>

int main(){
    int p, v;
    scanf("%d %d", &p, &v);
    char ** pname = (char **)malloc(sizeof(char *)*p);
    int * pnum = (int *)malloc(sizeof(int)*p);
    int * pvote = (int *)malloc(sizeof(int)*p);
    int alvote = 0;
    int * check = (int *)malloc(sizeof(int)*p);
    int checkn = 0;
    int R = 253;
    for(int i=0;i<p;i++){
        pname[i] = (char *)malloc(sizeof(char)*50);
        scanf("%s", pname[i]);
        scanf("%d %d", &pnum[i], &pvote[i]);
        check[i] = 0;
        if((double)pvote[i] / v >= 0.03 || pnum[i] >= 5){
            alvote += pvote[i];
            check[i] = 1;
            checkn ++;
            R -= pnum[i];
        }
    }
    double * pi = (double *)malloc(sizeof(double)*p);
    int * si = (int *)malloc(sizeof(int)*p);
    int sisum = 0;
    for(int i=0;i<p;i++){
        if(check[i] == 0){
            continue;
        }
        pi[i] = (double)pvote[i] / alvote;
        double st = ((300 - R) * pi[i] - pnum[i])/2;
        if(st < 1){
            si[i] = 0;
        }else{
            si[i] = (int)(st + 0.5);
        }
        sisum += si[i];
    }
    double * si2 = (double *)malloc(sizeof(double)*p);
    int sisum2 = 30;
    if(sisum < 30){
        for(int i=0;i<p;i++){
            if(check[i] == 0){
                si2[i] = 0.0;
                continue;
            }
            si2[i] = si[i] + (30 - sisum) * pi[i];
            si[i] = (int)si2[i];
            sisum2 -= si[i];
            si2[i] -= si[i];
        }
        while(sisum2 > 0){
            if(sisum2 >= checkn){
                for(int i=0;i<p;i++){
                    if(check[i] == 1){
                        si[i] ++;
                    }
                }
                sisum2 -= checkn;
                continue;
            }
            int index = 0;
            double maxsi2 = -0.1;
            for(int i=0;i<p;i++){
                if(maxsi2 < si2[i]){
                    index = i;
                    maxsi2 = si2[i];
                }
            }
            si[index] ++;
            si2[index] = 0.0;
            sisum2 --;
        }
    }else if(sisum > 30){
        for(int i=0;i<p;i++){
            if(check[i] == 0){
                si2[i] = 0.0;
                continue;
            }
            si2[i] = 30 * si[i] / (double)sisum;
            si[i] = (int)si2[i];
            sisum2 -= si[i];
            si2[i] -= si[i];
        }
        while(sisum2 > 0){
            if(sisum2 >= checkn){
                for(int i=0;i<p;i++){
                    if(check[i] == 1){
                        si[i] ++;
                    }
                }
                sisum2 -= checkn;
                continue;
            }
            int index = 0;
            double maxsi2 = -0.1;
            for(int i=0;i<p;i++){
                if(maxsi2 < si2[i]){
                    index = i;
                    maxsi2 = si2[i];
                }
            }
            si[index] ++;
            si2[index] = 0.0;
            sisum2 --;
        }
    }
    int * ti = (int *)malloc(sizeof(int)*p);
    double * ti2 = (double *)malloc(sizeof(double)*p);
    int tisum2 = 17;
    for(int i=0;i<p;i++){
        if(check[i] == 0){
            ti2[i] = 0.0;
            continue;
        }
        ti2[i] = 17 * pi[i];
        ti[i] = (int)ti2[i];
        tisum2 -= ti[i];
        ti2[i] -= ti[i];
    }
    while(tisum2 > 0){
        if(tisum2 >= checkn){
            for(int i=0;i<p;i++){
                if(check[i] == 1){
                    ti[i] ++;
                }
            }
            tisum2 -= checkn;
            continue;
        }
        int index = 0;
        double maxti2 = -0.1;
        for(int i=0;i<p;i++){
            if(maxti2 < ti2[i]){
                index = i;
                maxti2 = ti2[i];
            }
        }
        ti[index] ++;
        ti2[index] = 0.0;
        tisum2 --;
    }
    for(int i=0;i<p;i++){
        if(check[i] == 1){
            pnum[i] += si[i] + ti[i];
        }
        check[i] = 0;
    }
    int * order = (int *)malloc(sizeof(int)*p);
    for(int i=0;i<p;i++){
        int Maxp = -1;
        int index = 0;
        for(int j=0;j<p;j++){
            if(check[j] == 1){
                continue;
            }
            if(Maxp < pnum[j]){
                Maxp = pnum[j];
                index = j;
            }else if(Maxp == pnum[j]){
                for(int c=0;c<50;c++){
                    if(pname[index][c] < pname[j][c]){
                        break;
                    }else if(pname[index][c] > pname[j][c]){
                        index = j;
                        break;
                    }
                }
            }
        }
        check[index] = 1;
        order[i] = index;
    }
    for(int i=0;i<p;i++){
        int index = order[i];
        printf("%s %d\n", pname[index], pnum[index]);
    }
    return 0;
}