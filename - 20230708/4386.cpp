#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

double dis(double, double, double, double);

int main(){
    int n;
    scanf("%d", &n);
    vector<pair<double,double>> xy;
    priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;
    int * check = new int[n];

    for(int i=0;i<n;i++){
        double x, y;
        scanf("%lf %lf", &x, &y);
        xy.push_back({x, y});
    }

    double leng = 0.0;
    pq.push({0.0, 0});
    while(1){
        if(pq.empty()){
            break;
        }
        pair<double, int> nw = pq.top();
        pq.pop();
        if(check[nw.second] == 1){
            continue;
        }
        check[nw.second] = 1;
        leng += nw.first;

        for(int i=0;i<n;i++){
            if(check[i] == 1 || i == nw.second){
                continue;
            }
            pq.push({dis(xy[nw.second].first,xy[nw.second].second,xy[i].first,xy[i].second), i});
        }
    }

    printf("%.2lf\n", leng);
    return 0;
}

double dis(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}