#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll res=0;
int n,a;
int back[2];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    stack<int> st;
    for(int i=0;i<n;i++){
        cin >> a;
        back[i%2]=0;
        while(!st.empty()){
            if(st.top()>a){
                res++;
                back[i%2]++;
                break;
            }
            if(st.top()==a){
                res+=back[!(i%2)];
                back[i%2]+=back[!(i%2)];
                break;
            }
            st.pop();
            back[i%2]++;
            res++;
        }
        st.push(a);
    }
    cout << res;
    return 0;
}