#include <bits/stdc++.h>
using namespace std;

int n,rev[1000001],nx=1;
bool vis[1000001]={0,};
vector<int> ans;
queue<int> q;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    q.push(n); vis[n]=1;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        if(now==1) break;
        for(int dx:{3,2}){
            if(now%dx==0 && !vis[now/dx]){q.push(now/dx);rev[now/dx]=now;vis[now/dx]=1;}
        }
        if(!vis[now-1]){
            q.push(now-1);
            rev[now-1]=now;
            vis[now-1]=1;
        }
    }
    while(nx!=n){
        ans.push_back(nx);
        nx=rev[nx];
    }
    cout << ans.size() << '\n' << n << ' ';
    for(int i=ans.size()-1;i>=0;i--) cout << ans[i] << ' ';
    return 0;
}