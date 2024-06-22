#include <bits/stdc++.h>
#define INF 6e8
typedef long long ll;
using namespace std;

struct eg{
    int s,d;
    ll co;
};

int n,m;
vector<ll> d;
vector<eg> e;

bool bellman_ford(int start){
    d[start]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int cur=e[j].s;
            int next=e[j].d;
            int cost=e[j].co;
            if(d[cur]!=INF && d[next]>d[cur]+cost){
                if(i==n-1) return 1;
                d[next]=d[cur]+cost;
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    d.resize(n,INF);
    for(int i=0;i<m;i++){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        eg t;
        t.s=--a;
        t.d=--b;
        t.co=c;
        e.push_back(t);
    }
    if(bellman_ford(0)) cout << -1;
    else{
        for(int i=1;i<n;i++){
            cout << (d[i]!=INF?d[i]:-1) << '\n';
        }
    }
    return 0;
}
