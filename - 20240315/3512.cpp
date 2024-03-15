#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    double cost;
    cin >> cost;

    int sq_basic = 0;
    int sq_bed = 0;
    int sq_bal = 0;
    while(n--){
        int x;
        string name;
        cin >> x >> name;
        
        if(name == "bedroom"){
            sq_bed += x;
        }else if(name == "balcony"){
            sq_bal += x;
        }else{
            sq_basic += x;
        }
    }
    cout.precision(10);
    cout << sq_basic+sq_bed+sq_bal << "\n" << sq_bed << "\n" << cost/2*(2*(sq_basic+sq_bed)+sq_bal) << "\n";
    return 0;
}