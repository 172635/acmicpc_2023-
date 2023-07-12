#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    k--;
    int * candy = new int[n];
    for(int i=0;i<n;i++){
        scanf("%d", &candy[i]);
    }
    vector<int> * flink = new vector<int> [n];
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        flink[a-1].push_back(b-1);
        flink[b-1].push_back(a-1);
    }
    vector<int> check(n, 0);
    queue<int> q;

    vector<int> Gcost;
    vector<int> Gcandy;

    for(int i=0;i<n;i++){
        if(check[i] == 1){
            continue;
        }
        q.push(i);
        check[i] = 1;
        int Gnum = 0;
        int Gcnum = 0;
        while(!q.empty()){
            int nw = q.front();
            q.pop();
            Gnum ++;
            Gcnum += candy[nw];
            for(int j=0;j<flink[nw].size();j++){
                int nx = flink[nw][j];
                if(check[nx] == 0){
                    check[nx] = 1;
                    q.push(nx);
                }
            }
        }
        if(k >= Gnum){
            Gcost.push_back(Gnum);
            Gcandy.push_back(Gcnum);
        }
    }
    int * nowMax = new int [k+1];
    int * prevMax = NULL;
    for(int i=0;i<=k;i++){
        nowMax[i] = 0;
    }
    for(int i=0;i<Gcost.size();i++){
        delete[] prevMax;
        prevMax = nowMax;
        nowMax = new int [k+1];
        for(int j=0;j<=k;j++){
            nowMax[j] = prevMax[j];
            if(j >= Gcost[i] && nowMax[j] < prevMax[j - Gcost[i]] + Gcandy[i]){
                nowMax[j] = prevMax[j - Gcost[i]] + Gcandy[i];
            }
        }
    }
    printf("%d", nowMax[k]);
    return 0;
}