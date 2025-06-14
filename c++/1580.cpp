#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
using namespace std;

int dx[]={0,-1,-1,-1,0,1,1,1};
int dy[]={1,1,0,-1,-1,-1,0,1};
int n,m;
char g[21][21];
int ax,ay,bx,by;
int ad[21][21];
int bd[21][21];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        cin >> g[i][j];
        if(g[i][j]=='A'){
            ax=i;
            ay=j;
        }
        if(g[i][j]=='B'){
            bx=i;
            by=j;
        }
    }
    queue<pair<pair<int,int>,int>> q;
    q.push({{ax,ay},0});
    q.push({{bx,by},0});
    return 0;
}