#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct p{
    int x,y,v,p;
};

double d(p &a, p &b){ return sqrt((double)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); };

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,k,t;
    cin >> n >> k >> t;
    vector<vector<int>> graph(n+1);
    vector<p> a(n+1);
    cin >> a[0].x >> a[0].y >> a[0].v;
    for(int i=1;i<=n;i++){
        cin >> a[i].x >> a[i].y >> a[i].v >> a[i].p;
        for(int j=0;j<i;j++) if(d(a[i],a[j])<=(double)k && abs(a[i].v-a[j].v)<=t){
            graph[i].push_back(j);
            graph[j].push_back(i);
        }
    }
    vector<int> ans;
    bool vis[3001];
    memset(vis,0,sizeof(vis));
    queue<int> q;
    q.push(0);
    vis[0]=1;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<graph[now].size();i++){
            int nx=graph[now][i];
            if(vis[nx]) continue;
            if(a[nx].p) ans.push_back(nx);
            q.push(nx);
            vis[nx]=1;
        }
    }
    sort(ans.begin(),ans.end());
    if(ans.size()==0) cout << 0;
    else for(int &t:ans) cout << t << ' ';
    return 0;
}