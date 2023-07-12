#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    for(int i=0;i<m;i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--;
        b--;
        pq.push({c, {a, b}});
    }
    int num = 0;
    int sum = 0;
    vector<int> parent(n);
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    while(num < n-2){
        pair<int,pair<int,int>> nw = pq.top();
        pq.pop();
        int a, b, c;
        a = nw.second.first;
        b = nw.second.second;
        c = nw.first;
        int pa = parent[a];
        int pb = parent[b];
        while(pa != parent[pa]){
            pa = parent[pa];
        }
        parent[a] = pa;
        while(pb != parent[pb]){
            pb = parent[pb];
        }
        parent[b] = pb;

        if(pa == pb){
            continue;
        }else{
            sum += c;
            num ++;
            parent[pb] = pa;
        }
    }
    printf("%d\n", sum);
    return 0;
}