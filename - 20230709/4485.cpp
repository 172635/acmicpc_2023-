#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

int main(){
    int n;
    int field[130][130];
    int fsum[130][130];
    for(int pn = 1;;pn++){
        scanf("%d", &n);
        if(n == 0){
            break;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d", &field[i][j]);
                fsum[i][j] = -1;
            }
        }
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({field[0][0], {0, 0}});
        fsum[0][0] = field[0][0];
        while(!pq.empty()){
            pair<int,pair<int,int>> nw = pq.top();
            pq.pop();
            int nsf = nw.second.first;
            int nss = nw.second.second;
            if(nsf == n-1 && nss == n-1){
                break;
            }
            for(int i=0;i<4;i++){
                if(nsf + dx[i] < 0 || nsf + dx[i] > n-1 || nss + dy[i] < 0 || nss + dy[i] > n-1){
                    continue;
                }
                if(fsum[nsf + dx[i]][nss + dy[i]] == -1){
                    fsum[nsf+dx[i]][nss+dy[i]] = nw.first + field[nsf+dx[i]][nss+dy[i]];
                    pq.push({nw.first + field[nsf+dx[i]][nss+dy[i]], {nsf+dx[i], nss+dy[i]}});
                }
            }
        }
        printf("Problem %d: %d\n", pn, fsum[n-1][n-1]);
    }
    return 0;
}