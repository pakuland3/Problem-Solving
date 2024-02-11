#include <bits/stdc++.h>
using namespace std;

int t;
int l;
pair<int, int> np;
pair<int, int> dep;
int dx[]={-2,-2,-1,1,2,2,1,-1};
int dy[]={-1,1,2,2,1,-1,-2,-2};

void solve(){
    cin >> l; cin >> np.first >> np.second; cin >> dep.first >> dep.second;
    bool vis[300][300];
    memset(vis,false,sizeof(vis));
    queue<tuple<int, int, int>> q;
    q.push({np.first, np.second,0});
    vis[np.first][np.second]=true;
    while(!q.empty()){
        tuple<int, int, int> now=q.front();
        if(get<0>(now)==dep.first && get<1>(now)==dep.second) break;
        q.pop();
        for(int i=0;i<8;i++){
            int nx=get<0>(now)+dx[i]; int ny=get<1>(now)+dy[i];
            if(-1<nx && nx<l && -1<ny && ny<l && !vis[nx][ny]){
                q.push({nx, ny, get<2>(now)+1});
                vis[nx][ny]=true;
            }
        }
    }
    cout << get<2>(q.front()) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    while(t--) solve();
}