#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
using namespace std;

int n,q;
int g=0;
ll mm;
map<string,pair<ll,ll>> m[101];

void buy(string &a, ll cnt){
    for(int i=1;i<=g;i++){
        if(m[i].find(a)!=m[i].end() && mm>=cnt*m[i][a].fi){
            mm-=cnt*m[i][a].fi;
            m[i][a].se+=cnt;
        }
    }
}

void sell(string &a, ll cnt){
    for(int i=1;i<=g;i++){
        if(m[i].find(a)!=m[i].end()){
            int t=min(cnt,m[i][a].se);
            mm+=m[i][a].fi*t;
            m[i][a].se-=t;
        }
    }
}

void vary_one(string &a, ll d){
    for(int i=1;i<=g;i++){
        if(m[i].find(a)!=m[i].end()) m[i][a].fi+=d/10*10;
    }
}

void vary_group1(string &a, ll d){
    int t=stoi(a);
    for(auto it=m[t].begin();it!=m[t].end();it++) it->se.fi+=d/10*10;
}

void vary_group2(string &a, ll d){
    int t=stoi(a);
    for(auto it=m[t].begin();it!=m[t].end();it++){
        ll v=it->se.fi;
        it->se.fi=v*(100+d)/1000*10;;
    }
}

ll expected(){
    ll ret=mm;
    for(int i=1;i<=g;i++) for(auto it=m[i].begin();it!=m[i].end();it++) ret+=it->se.fi*it->se.se;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> mm >> q;
    for(int i=0;i<n;i++){
        int t;
        string tt;
        int p;
        cin >> t >> tt >> p;
        p=p/10*10;
        g=max(g,t);
        m[t][tt].fi=p;
        m[t][tt].se=0;
    }
    while(q--){
        int t,v;
        string a;
        cin >> t;
        if(t!=6 && t!=7) cin >> a >> v;
        if(t==1) buy(a,v);
        if(t==2) sell(a,v);
        if(t==3) vary_one(a,v);
        if(t==4) vary_group1(a,v);
        if(t==5) vary_group2(a,v);
        if(t==6) cout << mm << '\n';
        if(t==7) cout << expected() << '\n';
    }
    return 0;
}