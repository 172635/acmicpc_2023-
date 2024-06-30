#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    string s1, s2;
    cin >> s1 >> s2;
    long long int c;
    cin >> c;

    int zero1left = 0, zero1right = 0, zero1in = 0, zero2left = 0, zero2right = 0, zero2in = 0;
    int max_len = 0;
    int now_len = 0;
    int check = 0;
    for(int i=0;i<s1.size();i++){
        if(s1[i] == '0'){
            now_len ++;
        }else{
            max_len = max_len > now_len ? max_len : now_len;
            now_len = 0;
            if(check == 0){zero1left = max_len; check = 1;}
        }
        if(i == s1.size()-1){
            zero1right = now_len; 
            zero1in = max_len > now_len ? max_len : now_len;
        }
    }
    max_len = 0, now_len = 0, check = 0;
    for(int i=0;i<s2.size();i++){
        if(s2[i] == '0'){
            now_len ++;
        }else{
            max_len = max_len > now_len ? max_len : now_len;
            now_len = 0;
            if(check == 0){zero2left = max_len; check = 1;}
        }
        if(i == s2.size()-1){
            zero2right = now_len;
            zero2in = max_len > now_len ? max_len : now_len;
        }
    }
    int zero1inf = 0, zero2inf = 0;
    zero1inf = zero1in == s1.size() ? zero1in : 0;
    zero2inf = zero2in == s2.size() ? zero2in : 0;
    long long int t_max = 10000000000000000;
    int t1 = 1000000;

    if(zero1inf != 0 && zero2inf != 0){
        cout << 0 << "\n";
    }else if(zero1inf != 0){
        if(c <= zero1inf * t1 + zero2left){
            cout << 0 << "\n";
        }else if(c <= zero1inf * t1 + zero2left + zero2right){
            cout << s1.size() * t1 + s2.size() - zero2right << "\n";
        }else{
            cout << -1 << "\n";
        }
    }else if(zero2inf != 0){
        if(c <= zero1in){
            now_len = 0;
            for(int i=0;i<s1.size();i++){
                if(s1[i] == '0'){
                    now_len ++;
                    if(now_len == c){
                        cout << i - c + 1 << "\n";
                        break;
                    }
                }else{
                    now_len = 0;
                }
            }
        }else if(c <= zero1right + zero1left){
            cout << s1.size() - zero1right << "\n";
        }else{
            double num = (c - zero1left - zero1right - 1) / zero2inf;
            double check = (num+1) * s1.size() * t1 + num * (num+1) / 2 * s2.size() - zero1right + c;
            if(check <= t_max){
                long long int llnum = (c - zero1left - zero1right - 1) / zero2inf;
                cout << (llnum+1) * s1.size() * t1 + llnum * (llnum+1) / 2 * s2.size() - zero1right;
            }else{
                cout << -1 << "\n";
            }
        }
    }else{
        if(c <= zero1in){
            now_len = 0;
            for(int i=0;i<s1.size();i++){
                if(s1[i] == '0'){
                    now_len ++;
                    if(now_len == c){
                        cout << i - c + 1 << "\n";
                        break;
                    }
                }else{
                    now_len = 0;
                }
            }
        }else if(c <= zero1right + zero1left){
            cout << s1.size() - zero1right << "\n";
        }else if(c <= zero1right + zero2left){
            cout << s1.size() * t1 - zero1right << "\n";
        }else if(c <= zero2in){
            now_len = 0;
            for(int i=0;i<s2.size();i++){
                if(s2[i] == '0'){
                    now_len ++;
                    if(now_len == c){
                        cout << s1.size() * t1 + i - c + 1 << "\n";
                        break;
                    }
                }else{
                    now_len = 0;
                }
            }
        }else if(c <= zero2right + zero1left){
            cout << s1.size() * t1 + s2.size() - zero2right << "\n";
        }else if(c <= zero2right + zero2left){
            cout << s1.size() * 2 * t1 + s2.size() * 2 - zero2right << "\n";
        }else{
            cout << -1 << "\n";
        }
    }
    return 0;
}