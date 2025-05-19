#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(k);
    vector<pair<int,pair<int,int>>> edges(m);
    for(int &t:a) cin >> t;
    for(auto &t:edges) cin >> t.fi >> t.se.fi >> t.se.se;
    sort(edges.begin(),edges.end());
    vector<int> inf(n+1,0);
    unordered_set<int> s;
    for(int &t:a){
        s.clear();
        fill(inf.begin(),inf.end(),0);
        inf[t]=1;
        s.insert(t);
        for(auto &p:edges) if(inf[p.se.fi]){
            inf[p.se.se]=1;
            s.insert(p.se.se);
        }
        if(s.size()!=k) continue;
        int res=0;
        for(int &tt:a) if(s.find(tt)!=s.end()) res++;
        if(res!=k) continue;
        cout << t;
        return 0;
    }
    return 0;
}