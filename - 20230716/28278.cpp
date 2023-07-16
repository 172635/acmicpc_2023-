#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int x, x1;
    stack<int> st;
    for(int i=0;i<n;i++){
        scanf("%d", &x);
        if(x == 1){
            scanf("%d", &x1);
            st.push(x1);
        }else if(x == 2){
            if(st.empty()){
                printf("-1\n");
            }else{
                x1 = st.top();
                st.pop();
                printf("%d\n", x1);
            }
        }else if(x == 3){
            printf("%d\n", st.size());
        }else if(x == 4){
            printf("%d\n", st.empty());
        }else{
            if(st.empty()){
                printf("-1\n");
            }else{
                printf("%d\n", st.top());
            }
        }
    }
    return 0;
}