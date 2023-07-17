#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    if(n < m + k - 1 || n > m * k){
        printf("-1\n");
        return 0;
    }
    int nt = n;
    vector<int> ans;
    while(m > 0){
        int x = 1;
        if(nt - 1 > (m-1)*k){
            x = nt - (m-1)*k;
        }
        int diff = n - nt;
        for(int i = x; i > 0; i--){
            ans.push_back(i+diff);
        }
        nt -= x;
        m --;
    }
    for(int i=0;i<ans.size();i++){
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}