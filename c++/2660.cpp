#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> graph(n+1);
    vector<vector<int>> depth(n+1);
    while(1){
        int a,b;
        cin >> a >> b;
        if(a==-1) break;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        vector<bool> vis(n,0);
        queue<pair<int, int>> q;
        int maxi=0,cnt=1;
        q.push({i,0});
        vis[i]=1;
        while(!q.empty()){
            pair<int,int> now=q.front();
            q.pop();
            for(int j=0;j<graph[now.first].size();j++){
                if(!vis[graph[now.first][j]]){
                    q.push({graph[now.first][j],now.second+1});
                    maxi=max(maxi,now.second+1);
                    vis[graph[now.first][j]]=1;
                    cnt++;
                }
            }
        }
        if(cnt<n) depth[0].push_back(i);
        else depth[maxi].push_back(i);
    }
    for(int i=0;i<=n;i++){
        if(depth[i].size()>0){
            cout << i << ' ' << depth[i].size() << '\n';
            for(int &ans:depth[i]) cout << ans << ' ';
            break;
        }
    }
    return 0;
}