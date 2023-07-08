#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t > 0){
        int n, k;
        scanf("%d %d", &n, &k);
        vector<int> time;
        for(int i=0;i<n;i++){
            int x;
            scanf("%d", &x);
            time.push_back(x);
        }
        vector<int> * rule = new vector<int> [n];
        int * ruleN = new int [n]();
        for(int i=0;i<k;i++){
            int x, y;
            scanf("%d %d", &x, &y);
            rule[x - 1].push_back(y - 1);
            ruleN[y - 1] ++;
        }
        int goal;
        scanf("%d", &goal);
        goal --;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            if(ruleN[i] == 0){
                pq.push({time[i], i});
            }
        }
        int gtime = 0;
        while(!pq.empty()){
            pair<int,int> nw = pq.top();
            pq.pop();
            if(nw.second == goal){
                gtime = nw.first;
                break;
            }
            for(int i=0;i<rule[nw.second].size();i++){
                int nx = rule[nw.second][i];
                ruleN[nx] --;
                if(ruleN[nx] == 0){
                    pq.push({nw.first + time[nx], nx});
                }
            }
        }
        printf("%d\n", gtime);
        
        t--;
    }
}