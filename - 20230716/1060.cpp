#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int ssize;
    scanf("%d", &ssize);
    vector<int> s;
    for(int i=0;i<ssize;i++){
        int x;
        scanf("%d", &x);
        s.push_back(x);
    }
    s.push_back(0);
    sort(s.begin(), s.end());

    int sbig = s[ssize];
    vector<pair<int,int>> emp; // size, end
    for(int i=1;i<=ssize;i++){
        emp.push_back({s[i] - s[i-1] - 1, s[i]});
    }

    priority_queue<pair<long long int,int>, vector<pair<long long int,int>>, greater<pair<long long int,int>>> pq;
    for(int i=0;i<emp.size();i++){
        int esize = emp[i].first;
        int eend = emp[i].second;
        if(esize <= 100){
            pq.push({0, eend});
            long long int sum = -1;
            for(int j=1;j<=esize/2;j++){
                sum += (esize - (j-1)*2);
                pq.push({sum, eend - j});
                pq.push({sum, eend - esize - 1 + j});
            }
            if(esize % 2 == 1){
                sum += 1;
                pq.push({sum, eend - (esize+1)/2});
            }
        }else{
            pq.push({0, eend});
            long long int sum = -1;
            for(int j=1;j<=50;j++){
                sum += (esize - (j-1)*2);
                pq.push({sum, eend - j});
                pq.push({sum, eend - esize - 1 + j});
            }
        }
    }

    int N;
    scanf("%d", &N);
    while(N > 0){
        if(pq.empty()){
            for(int i=1;i<=N;i++){
                printf("%d ", sbig + i);
            }
            break;
        }else{
            pair<long long int,int> nw = pq.top();
            pq.pop();
            printf("%d ", nw.second);
            N --;
        }
    }
    return 0;
}