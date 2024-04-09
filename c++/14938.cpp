#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n,m,r,graph[101][101],a,b,c,ans=0,sum;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> r;
    for(int i=1;i<=n;i++) fill(graph[i],graph[i]+101,INF);
    vector<int> items(n+1);
    for(int i=1;i<=n;i++) cin >> items[i];
    for(int i=0;i<r;i++){
        cin >> a >> b >> c;
        graph[a][b]=min(graph[a][b],c);
        graph[b][a]=min(graph[b][a],c);
    }
    for(int i=1;i<=n;i++) graph[i][i]=0;
    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
    for(int i=1;i<=n;i++){
        sum=0;
        for(int j=1;j<=n;j++) if(graph[i][j]<=m) sum+=items[j];
        ans=max(ans,sum);
    }
    cout << ans;
    return 0;
}