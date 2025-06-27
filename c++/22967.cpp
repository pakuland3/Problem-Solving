#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int adj[301][301];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        adj[a][b]=1;
        adj[b][a]=1;
    }
    vector<pair<int,int>> ans;
    if(n<5){
        for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) if(!adj[i][j]) ans.push_back({i,j});
    }
    else for(int i=2;i<=n;i++) if(!adj[1][i]) ans.push_back({1,i});
    cout << ans.size() << '\n' << (n>4)+1 << '\n';
    for(auto t:ans) cout << t.first << ' ' << t.second << '\n';
    return 0;
}