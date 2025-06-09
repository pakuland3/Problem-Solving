#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> g[200001];
int ans[200001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int x;
    cin >> x;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    ans[1]=x/(a[1]>=x?2:1);
    queue<int> q;
    q.push(1);
    while(q.size()){
        int now=q.front();
        q.pop();
        for(int nx:g[now]){
            int nv=ans[now]/(a[nx]>=ans[now]?2:1);
            if(nv>ans[nx]){
                ans[nx]=nv;
                q.push(nx);
            }
        }
    }
    cout << ans[n];
    return 0;
}