#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n,m,graph[101][101],a,b,c;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=1;i<=n;i++) fill(graph[i],graph[i]+101,INF);
    for(int i=0;i<m;i++){
        cin >> a >> b >> c; graph[a][b]=min(graph[a][b],c);
    }
    for(int i=1;i<=n;i++) graph[i][i]=0;
    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(graph[i][j]==INF) cout << "0 ";
            else cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}