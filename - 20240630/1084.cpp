#include <bits/stdc++.h>

using namespace std;

void printnum(int iter, int num){
    while(iter--){
        cout << num;
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<long long int> numcost;
    int mini = -1;
    for(int i=0;i<n;i++){
        long long int x;
        cin >> x;
        numcost.push_back(x);
        if(mini == -1 || numcost[mini] >= x){mini = i;}
    }
    long long int money;
    cin >> money;

    int checker = 0;
    if(numcost[mini] > money){cout << 0 << "\n" << "\n" << endl;}
    else if(mini == 0){
        mini = -1;
        for(int i=1;i<n;i++){
            if(mini == -1 || numcost[mini] > numcost[i]){mini = i;}
        }
        if(mini == -1 || numcost[mini] > money){cout << 1 << "\n" << 0 << "\n" << 0 << endl;}
        else{
            mini = 0;
            checker = 1;
        }
    }else{
        checker = 1;
    }
    if(checker == 1){
        long long int length = money / numcost[mini];
        vector<pair<int,long long int>> more;
        money -= numcost[mini] * length;
        int maxi;
        while(true){
            maxi = -1;
            for(int i=n-1;i>mini;i--){
                if(money >= numcost[i] - numcost[mini]){maxi = i; break;}
            }
            if(maxi == -1){break;}
            more.push_back({maxi, money/(numcost[maxi] - numcost[mini])});
            money -= (numcost[maxi] - numcost[mini]) * more[more.size()-1].second;
        }

        if(mini == 0 && more.size() == 0){
            int mini = -1;
            for(int i=1;i<n;i++){
                if(mini == -1 || numcost[mini] > numcost[i]){mini = i;}
            }
            money += numcost[0] * length;
            length = (money - numcost[mini]) / numcost[0] + 1;
            mini = 0;
            money -= numcost[mini] * length;
            while(true){
                maxi = -1;
                for(int i=n-1;i>mini;i--){
                    if(money >= numcost[i] - numcost[mini]){maxi = i; break;}
                }
                if(maxi == -1){break;}
                more.push_back({maxi, money/(numcost[maxi] - numcost[mini])});
                money -= (numcost[maxi] - numcost[mini]) * more[more.size()-1].second;
            }
        }
        cout << length << "\n";

        long long int _len = length <= 50 ? length : 50;
        for(int i=0;i<more.size();i++){
            if(more[i].second <= _len){
                printnum((int)more[i].second, more[i].first);
                _len -= more[i].second;
            }else{
                printnum(_len, more[i].first);
                _len = 0;
                break;
            }
        }
        if(_len > 0){printnum(_len, mini);}
        cout << "\n";

        long long int st_len = length > 50 ? length - 50 : 0;
        long long int en_len = length;
        for(int i=0;i<more.size();i++){
            st_len -= more[i].second;
            en_len -= more[i].second;
            if(st_len < 0){
                if(en_len > 0){
                    printnum(-st_len, more[i].first);
                    st_len = 0;
                }else{
                    printnum(en_len - st_len, more[i].first);
                    st_len = 0;
                    en_len = 0;
                    break;
                }
            }
        }
        if(en_len > 0){
            printnum(en_len - st_len, mini);
        }
        cout << endl;
    }
    return 0;
}