#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d\n", &n);
    vector<int> solution;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d", &x);
        solution.push_back(x);
    }
    sort(solution.begin(), solution.end());
    int st = 0, en = n - 1;
    int a = st, b = en, min = solution[st] + solution[en];
    while(st < en){
        int tempmin = solution[st] + solution[en];
        if(abs(min) > abs(tempmin)){
            min = tempmin;
            a = st;
            b = en;
        }
        if(tempmin < 0){
            st ++;
        }else{
            en --;
        }
    }
    printf("%d %d\n", solution[a], solution[b]);
    return 0;
}