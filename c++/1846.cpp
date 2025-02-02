#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    if(n==3){
        cout << -1;
        return 0;
    }
    int vis[100000];
    memset(vis,0,sizeof(vis));
    int x=n/2;
    for(int i=0;i<n;i++,x++){
        if(x==i || n-(i+1)==x) x++;
        if(x==n) x=0;
        if(vis[x]){
            for(int j=0;j<n;j++) if(!vis[j] && j!=n-(i+1) && j!=i){
                cout << j+1;
                vis[j]=1;
                break;
            }
        }
        else{
            cout << x+1;
            vis[x]=1;
        }
        cout << '\n';
    }
    return 0;
}