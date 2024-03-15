#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    while(n--){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int s;
    cin >> s;
    long long int num = 0;
    for(int i=0;i<v.size();i++){
        num += v[i] / s + (v[i] % s != 0);
    }
    cout << s * num;
    return 0;
}