#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int idc[501];
int adj[501][501];
int vis[501];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        memset(vis,0,sizeof(vis));
        memset(idc,0,sizeof(idc));
        fill(adj[0],adj[501],0);
        vector<int> order;
        int n;
        cin >> n;
        vector<int> a(n);
        for(int &t:a) cin >> t;
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++){
            adj[a[i]][a[j]]=1;
            idc[a[j]]++;
        }
        int m;
        cin >> m;
        for(int i=0;i<m;i++){
            int b,c;
            cin >> b >> c;
            swap(adj[b][c],adj[c][b]);
            if(adj[b][c]){
                idc[c]++;
                idc[b]--;
            }
            else{
                idc[b]++;
                idc[c]--;
            }
        }
        queue<int> q;
        for(int i=1;i<=n;i++) if(!idc[i]){
            q.push(i);
            order.push_back(i);
        }
        int flag=1;
        while(q.size()){
            if(q.size()>1) flag=0;
            int now=q.front(); q.pop();
            for(int i=1;i<=n;i++){
                if(!adj[now][i]) continue;
                if(vis[i]) continue;
                idc[i]--;
                if(!idc[i]){
                    order.push_back(i);
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
        if(!flag || order.size()!=n) cout << "IMPOSSIBLE";
        else for(int &t:order) cout << t << ' ';
        cout << '\n';
    }
    return 0;
}