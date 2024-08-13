#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll a,b;
        cin >> a >> b;
        ll cur=a;
        vector<ll> c;
        while(1){
            bool b=0;
            for(int i=0;i<c.size();i++) if(c[i]==cur%10){
                b=1;
                break;
            }
            if(b) break;
            c.push_back(cur%10);
            cur*=a;
        }
        int idx=b%(int)c.size()-1;
        if(idx==-1) idx=c.size()-1;
        cout << (c[idx]==0?10:c[idx]) << '\n';
    }
    return 0;
}