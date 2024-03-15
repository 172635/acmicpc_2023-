#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    n--;
    int mid;
    cin >> mid;
    cout << mid << '\n';
    priority_queue<int> leftq;
    priority_queue<int, vector<int>, greater<int>> rightq;
    while(n--){
        int x;
        cin >> x;
        if(mid >= x){
            if(leftq.size() < rightq.size()){
                leftq.push(x);
            }else{
                leftq.push(x);
                rightq.push(mid);
                mid = leftq.top();
                leftq.pop();
            }
        }else{
            if(leftq.size() >= rightq.size()){
                rightq.push(x);
            }else{
                rightq.push(x);
                leftq.push(mid);
                mid = rightq.top();
                rightq.pop();
            }
        }
        cout << mid << '\n';
    }
    return 0;
}