#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

map<string,vector<string>> g;

int solve(string s, string e){
    map<string,int> vis;
    queue<string> q;
    q.push(s);
    vis[s]=1;
    while(q.size()){
        string now=q.front();
        if(now==e) return 1;
        q.pop();
        for(string nx:g[now]){
            if(vis.find(nx)!=vis.end()) continue;
            vis[nx]=1;
            q.push(nx);
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        string a,b;
        cin >> a >> b;
        if(g.find(a)==g.end()) g[a]=vector<string>();
        if(g.find(b)==g.end()) g[b]=vector<string>();
        g[b].push_back(a);
    }
    int q;
    cin >> q;
    while(q--){
        string a,b;
        cin >> a >> b;
        int ab=solve(a,b);
        int ba=solve(b,a);
        cout << (ab^ba?(ab?b:a):"gg") << ' ';
    }
    return 0;
}