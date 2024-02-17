#include <bits/stdc++.h>
using namespace std;

int t;

void solve(){
    int n;
    long long ans=0;
    vector<int> v;
    cin >> n; for(int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
    int maxi=v.back();
    for(int i=v.size()-2;i>-1;i--){
        if(v[i]>maxi) maxi=v[i];
        else if(v[i]<maxi) ans+=maxi-v[i];
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> t; while(t--) solve();
}