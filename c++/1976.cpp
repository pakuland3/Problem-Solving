#include <bits/stdc++.h>
using namespace std;

int n,parent[201],m;
bool inn;

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
    cin >> n >> m;
    for(int i=1;i<=n;i++) parent[i]=i;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        cin >> inn;
        if(inn) unionParent(i,j);
    }
    vector<int> trav(m);
    for(int i=0;i<m;i++) cin >> trav[i];
    for(int i=0;i<m-1;i++){
        if(getParent(trav[i])!=getParent(trav[i+1])){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}