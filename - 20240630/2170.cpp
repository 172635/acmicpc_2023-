#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    while(n--){
        int x1, x2;
        cin >> x1 >> x2;
        pq.push({x1, x2});
    }
    int paststart = -1000000000;
    int pastend = -1000000000;
    int lengthsum = 0;
    while(!pq.empty()){
        pair<int,int> now = pq.top();
        pq.pop();
        if(now.first >= pastend){
            lengthsum += (pastend - paststart);
            paststart = now.first;
            pastend = now.second;
        }else{
            pastend = pastend > now.second ? pastend : now.second;
        }
    }
    lengthsum += (pastend - paststart);
    cout << lengthsum << "\n";
    return 0;
}