#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    long long int n;
    int p, q;
    cin >> n >> p >> q;
    if(p < q){
        int temp = q;
        q = p;
        p = temp;
    }
    
    unordered_map<long long int, long long int> um;
    um[0] = 1;

    long long int sum = 0;
    priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
    pq.push(n);
    while(!pq.empty()){
        long long int now = pq.top();
        pq.pop();
        if(um.find(now) == um.end()){
            if(um.find(now/p) != um.end()){
                if(um.find(now/q) != um.end()){
                    um[now] = um[now/p] + um[now/q];
                    sum += um[now];
                }else{
                    sum += um[now/p];
                    pq.push(now/q);
                }
            }else if(um.find(now/q) != um.end()){
                sum += um[now/q];
                pq.push(now/p);
            }else{
                pq.push(now/p);
                pq.push(now/q);
            }
        }else{
            sum += um[now];
        }
    }
    cout << sum << "\n";
    return 0;
}