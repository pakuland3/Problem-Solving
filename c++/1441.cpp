#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    ll l,r;
    cin >> n >> l >> r;
    vector<int> a(n);
    l--;
    for(int &t:a) cin >> t;
    ll lans=0,rans=0;
    int cnt=1<<a.size();
    for(int i=1;i<cnt;i++){
        int j=i;
        int idx=0;
        bool odd=0;
        ll div=1;
        while(j){
            if(j&1){
                div=lcm(div,a[idx]);
                odd^=1;
            }
            idx++;
            j>>=1;
        }
        if(odd){
            lans+=l/div;
            rans+=r/div;
        }
        else{
            lans-=l/div;
            rans-=r/div;
        }
    }
    cout << rans-lans;
    return 0;
}