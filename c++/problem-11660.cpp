#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct pos{
    int x;
    int y;
};

int n,m;
int table[1024][1024];
pos s,e;
ll ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m; for(int i=0;i<n;i++) cin >> table[0][i];
    for(int i=1;i<n;i++) for(int j=0;j<n;j++){cin >> table[i][j];table[i][j]+=table[i-1][j];}
    while(m--){
        cin >> s.x >> s.y >> e.x >> e.y; s.x--; s.y--; e.x--; e.y--;
        ans=0;
        if(s.x==0) for(int i=s.y;i<=e.y;i++) ans+=table[e.x][i];
        else for(int i=s.y;i<=e.y;i++) ans+=table[e.x][i]-table[s.x-1][i];
        cout << ans << '\n';
    }
    return 0;
}