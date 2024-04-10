#include <bits/stdc++.h>
using namespace std;

int parent[1000001];

int getParent(int x){
    if(parent[x]==x) return x;
    return parent[x]=getParent(parent[x]);
}

void unionParent(int a, int b){
    a=getParent(a);
    b=getParent(b);
    if(a>b) parent[a]=b;
    else parent[b]=a;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,a,b;
    bool in;
    cin >> n >> m;
    for(int i=0;i<=n;i++) parent[i]=i;
    for(int i=0;i<m;i++){
        cin >> in >> a >> b;
        if(!in) unionParent(a,b);
        else{
            if(getParent(a)!=getParent(b)) cout << "NO\n";
            else cout << "YES\n";
        }
    }
    return 0;
}