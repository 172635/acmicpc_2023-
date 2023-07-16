#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int n36s[55][37];
    int n36[55][36];
    for(int i=0;i<55;i++){
        for(int j=0;j<37;j++){
            n36s[i][j] = 0;
        }
        for(int j=0;j<36;j++){
            n36[i][j] = 0;
        }
    }
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        char str[55];
        scanf("%s", str);
        int e;
        for(e = 0; str[e] != '\0'; e++){}
        if(e == 1 && str[0] == '0'){
            continue;
        }
        for(int j = 0; j < e; j++){
            char ch = str[e-1-j];
            int x;
            if(ch >= 'A'){
                x = ch - 'A' + 10;
            }else{
                x = ch - '0';
            }
            n36[j][x] ++;
        }
    }
    int x;
    scanf("%d", &x);
    for(int i=0;i<55;i++){
        for(int j=0;j<36;j++){
            n36s[i][j] += n36[i][j] * (35 - j);
            n36s[i][36] += n36[i][j] * j;
        }
        for(int j=0;j<37;j++){
            n36s[i+1][j] += n36s[i][j] / 36;
            n36s[i][j] %= 36;
        }
    }
    int check[36];
    for(int j=0;j<36;j++){
        check[j] = 0;
    }
    for(int i = 54; i>=0; i--){
        if(x <= 0){
            break;
        }
        priority_queue<pair<int,int>> pq;
        for(int j=0;j<36;j++){
            if(check[j] == 0){
                pq.push({n36s[i][j], j});
            }
        }
        vector<int> v;
        while(!pq.empty()){
            if(x <= 0){
                break;
            }
            pair<int,int> nw = pq.top();
            pq.pop();
            v.push_back(nw.second);
            if(nw.first > pq.top().first){
                if(v.size() <= x){
                    x-= v.size();
                    for(int vn = 0; vn<v.size(); vn++){
                        for(int vni=0;vni<55;vni++){
                            n36s[vni][36] += n36s[vni][v[vn]];
                        }
                        check[v[vn]] = -1;
                    }
                    v.clear();
                }else{
                    for(int ci = 0; ci < 36; ci++){
                        check[ci] = -1;
                    }
                    for(int vn = 0;vn<v.size();vn++){
                        check[v[vn]] = 0;
                    }
                    break;
                }

            }
        }
    }
    for(int i=0;i<55;i++){
        n36s[i+1][36] += n36s[i][36] / 36;
        n36s[i][36] %= 36;
    }
    int Zcheck = 0;
    for(int i=54;i>=0;i--){
        if(Zcheck == 0){
            if(n36s[i][36] != 0){
                Zcheck = 1;
            }else if(i == 0){
                printf("0");
                break;
            }else{
                continue;
            }
        }
        if(n36s[i][36] >= 10){
            printf("%c", 'A'+n36s[i][36]-10);
        }else{
            printf("%d", n36s[i][36]);
        }
    }
    printf("\n");
    return 0;
}