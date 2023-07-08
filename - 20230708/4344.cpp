#include <iostream>
#include <vector>

using namespace std;

int main(){
    int c;
    int n;
    vector<int> st;
    double aver;
    int temp;
    int over;
    cin >> c;
    for(int i=0;i<c;i++){
        cin >> n;
        st.clear();
        aver = 0.0;
        over = 0;
        for(int j=0;j<n;j++){
            cin >> temp;
            st.push_back(temp);
            aver += temp;
        }
        aver /= n;
        for(int j=0;j<n;j++){
            if(aver < st[j]){
                over ++;
            }
        }
        cout << fixed;
        cout.precision(3);
        cout << (float)over/n*100 << "%\n";
    }
    return 0;
}