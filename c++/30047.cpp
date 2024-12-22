#include <bits/stdc++.h>
#define fi first
#define se second
#define pci pair<char,int>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string a;
    cin >> a;
    stack<pci> st;
    int res=0;
    if(a.length()==1 && a[0]=='x'){
        cout << 0;
        return 0;
    }
    for(int i=0;i<a.length();i++){
        if(a[i]=='f') st.push({'f',0});
        if(a[i]=='g') st.push({'g',0});
        if(a[i]=='x'){
            pci cur={'x',0};
            while(!st.empty()){
                pci t=st.top();
                st.pop();
                if(t.fi=='f'){
                    cur={'h',cur.se};
                    break;
                }
                else if(t.fi=='g') cur={'k',cur.se+1};
                else if(t.fi=='h') cur={'k',min(cur.se,t.se)};
            }
            if(cur.fi=='x'){
                cout << -1;
                return 0;
            }
            st.push(cur);
        }
    }
    if(st.size()!=1 || st.top().fi!='k') cout << -1;
    else cout << st.top().se;
    return 0;
}