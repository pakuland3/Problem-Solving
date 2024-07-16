#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define MAX 10001
using namespace std;

struct node{
    int id,n;
};

int id,d[MAX];
bool finished[MAX];
vector<int> graph[MAX];
vector<vector<int>> SCC;
stack<node> s;

int dfs(int x){
    d[x]=++id;
    s.push({id,x});
    int parent=id;
    for(int i=0;i<(int)graph[x].size();i++){
        int y=graph[x][i];
        if(d[y]==0) parent=min(parent,dfs(y));
        else if(!finished[y]) parent=min(parent,d[y]);
    }
    if(parent==d[x]){
        vector<int> scc;
        while(1){
            int t=s.top().n;
            scc.push_back(t);
            finished[t]=1;
            s.pop();
            if(t==x) break;
        }
        SCC.push_back(scc);
    }
    return parent;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int v,e;
    cin >> v >> e;
    while(e--){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for(int i=1;i<=v;i++) if(d[i]==0) dfs(i);
    for(int i=0;i<SCC.size();i++) sort(SCC[i].begin(),SCC[i].end(),less<int>());
    sort(SCC.begin(),SCC.end(),[](vector<int> &l, vector<int> &r)->bool{return l[0]<r[0];});
    cout << SCC.size() << '\n';
    for(int i=0;i<SCC.size();i++){
        for(int j=0;j<SCC[i].size();j++){
            cout << SCC[i][j] << ' ';
        }
        cout << "-1\n";
    }
    return 0;
}