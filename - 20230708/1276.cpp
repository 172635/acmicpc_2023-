#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<pair<int, pair<int,int>>> v;
    for(int i=0;i<n;i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v.push_back({a, {b, c - 1}});
    }
    sort(v.begin(), v.end());
    int sum = 0;
    for(int i=0;i<n;i++){
        int p1, p2;
        p1 = v[i].first;
        p2 = v[i].first;
        int piL = v[i].second.first;
        int piR = v[i].second.second;
        for(int j=i-1;j>=0;j--){
            if(piL <= v[j].second.second && piL >= v[j].second.first){
                p1 -= v[j].first;
                break;
            }
        }
        for(int j=i-1;j>=0;j--){
            if(piR <= v[j].second.second && piR >= v[j].second.first){
                p2 -= v[j].first;
                break;
            }
        }
        sum += p1 + p2;
    }
    printf("%d\n", sum);
    return 0;
}