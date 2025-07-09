#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int G,p;
    cin >> G >> p;
    vector<int> g(p);
    for(int i=0;i<p;i++) cin >> g[i];
    set<int> s;
    int maxi=0;
    int res=0;
    for(int i=0;i<p;i++){
        for(int j=maxi+1;j<=G && j<=g[i];j++) s.insert(j);
        if(s.empty()) break;
        auto it=s.upper_bound(g[i]);
        if(it==s.begin()) break;
        s.erase(*prev(it));
        maxi=max(maxi,g[i]);
        res++;
    }
    cout << res;
    return 0;
}