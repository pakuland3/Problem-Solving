#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int parent[501];
int noTree[501];
int vis[501];

int getParent(int a){
    if(a==parent[a]) return a;
    return parent[a]=getParent(parent[a]);
}

void unionParent(int a, int b){
    a=getParent(a);
    b=getParent(b);
    if(a>b){
        parent[a]=b;
        noTree[b]=noTree[a]|noTree[b];
    }
    else{
        parent[b]=a;
        noTree[a]=noTree[a]|noTree[b];
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for(int tt=1;;tt++){
        int n,m;
        cin >> n >> m;
        if(n==0 && m==0) break;
        memset(noTree,0,sizeof(noTree));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++) parent[i]=i;
        int a,b;
        for(int i=0;i<m;i++){
            cin >> a >> b;
            a=getParent(a);
            if(a==getParent(b)) noTree[a]=1;
            else unionParent(a,b);
        }
        int res=0;
        for(int i=1;i<=n;i++){
            a=getParent(i);
            res+=!vis[a]&!noTree[a];
            vis[a]=1;
        }
        cout << "Case " << tt << ": ";
        if(res){
            if(res==1) cout << "There is one tree.";
            else cout << "A forest of " << res << " trees.";
        }
        else cout << "No trees.";
        cout << '\n';
    }
    return 0;
}