#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int * time = new int [n]();
    vector<int> * rule = new vector<int> [n];
    int * ruleN = new int [n]();

    for(int i=0;i<n;i++){
        int x;
        scanf("%d", &x);
        time[i] = x;
        while(1){
            scanf("%d", &x);
            if(x == -1){
                break;
            }
            rule[x-1].push_back(i);
            ruleN[i] ++;
        }
    }
    int * mintime = new int [n]();

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=0;i<n;i++){
        if(ruleN[i] == 0){
            pq.push({time[i], i});
            mintime[i] = time[i];
        }
    }
    while(!pq.empty()){
        pair<int,int> nw = pq.top();
        pq.pop();
        for(int i=0;i<rule[nw.second].size();i++){
            int nx = rule[nw.second][i];
            ruleN[nx] --;
            if(ruleN[nx] == 0){
                pq.push({nw.first + time[nx], nx});
                mintime[nx] = nw.first + time[nx];
            }
        }
    }

    for(int i=0;i<n;i++){
        printf("%d\n", mintime[i]);
    }
    return 0;
}