#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int div = 1000000007;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> tree[21];
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        tree[0].push_back(x);
    }
    int h;
    for(int i=1;i<21;i++){
        for(int j=0;j<tree[i-1].size()/2;j++){
            tree[i].push_back((tree[i-1][j*2] * (long long int)tree[i-1][j*2+1]) % div);
        }
        if(tree[i].size() > 0){h=i;}
    }
    for(int i=0;i<m+k;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            b--;
            tree[0][b] = c;
            for(int hi=1;hi<=h;hi++){
                b /= 2;
                if(tree[hi].size() <= b){break;}
                long long int temp = tree[hi-1][b*2] * (long long int)tree[hi-1][b*2+1];
                if(temp >= div){
                    tree[hi][b] = temp % div;
                }else{
                    tree[hi][b] = temp;
                }
            }
        }else if(a == 2){
            b--;
            c--;

            if(b == c){
                cout << tree[0][b] << "\n";
                continue;
            }

            int dif = h;
            int sum = 0;
            while(dif > 0){
                int hn = sum + (1 << dif);
                if(hn > b && hn > c){
                    dif --;
                }else if(hn <= b && hn <= c){
                    sum += (1 << dif);
                    dif --;
                }else{
                    break;
                }
            }
            long long int rest = 1;
            int b2, c2;
            int _b = b, _c = c;
            for(int i2=0;i2<dif;i2++){
                b2 = _b % 2;
                c2 = _c % 2;

                if(b2 == 0){
                    rest *= tree[i2][b / (1 << i2) + 1];
                    if(rest >= div){rest %= div;}
                }
                if(c2 == 1){
                    rest *= tree[i2][c / (1 << i2) - 1];
                    if(rest >= div){rest %= div;}
                }

                _b/=2;
                _c/=2;
            }
            rest *= tree[0][b];
            if(rest >= div){rest %= div;}
            rest *= tree[0][c];
            if(rest >= div){rest %= div;}

            cout << rest << "\n";
        }
    }
    return 0;
}