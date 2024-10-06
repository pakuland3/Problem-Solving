#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> a,b,c,d;

void solve(int idx, int cs, vector<int> &e, vector<int> &f){
    for(int i=idx+1;i<e.size();i++){
        cs+=e[i];
        f.push_back(cs);
        solve(i,cs,e,f);
        cs-=e[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,s;
    cin >> n >> s;
    a.resize(n/2);
    b.resize(n/2+n%2);
    for(int &t:a) cin >> t;
    for(int &t:b) cin >> t;
    solve(-1,0,a,c);
    solve(-1,0,b,d);
    ll res=0;
    sort(d.begin(),d.end());
    for(int &t:c){
        res+=(ll)((t==s)+upper_bound(d.begin(),d.end(),s-t)-lower_bound(d.begin(),d.end(),s-t));
    }
    for(int &t:d) res+=(ll)(t==s);
    cout << res; 
    return 0;
}