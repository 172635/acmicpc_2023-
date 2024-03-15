#include <bits/stdc++.h>

using namespace std;

vector<char> vi;
vector<char> vf;

long long int hanoi3(char now, char temp, char to, int n){
    if(n == 1){
        vi.push_back(now);
        vf.push_back(to);
        return 1;
    }
    int ret = 0;
    ret += hanoi3(now, to, temp, n-1);
    vi.push_back(now);
    vf.push_back(to);
    ret += hanoi3(temp, now, to, n-1);
    return ret+1;
}

long long int hanoi4(char now, char temp, char to, int n){
    if(n > 2){
        int ret = 0;
        ret += hanoi3(now, temp, to, n-2);
        vi.push_back(now);
        vf.push_back(temp);
        vi.push_back(now);
        vf.push_back('D');
        vi.push_back(temp);
        vf.push_back('D');
        ret += hanoi4(to, temp, now, n-2);
        ret += 3;
        return ret;
    }else if(n == 2){
        vi.push_back(now);
        vf.push_back(temp);
        vi.push_back(now);
        vf.push_back('D');
        vi.push_back(temp);
        vf.push_back('D');
        return 3;
    }else{
        vi.push_back(now);
        vf.push_back('D');
        return 1;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    long long int x = hanoi4('A', 'B', 'C', n);
    cout << x << '\n';
    string ret = "";
    for(int i=0;i<vi.size();i++){
        ret += vi[i];
        ret += " ";
        ret += vf[i];
        ret += "\n";
    }
    cout << ret;
    return 0;
}