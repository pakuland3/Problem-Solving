#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> parent;

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
    int n,m;
    cin >> n >> m;
    parent.resize(n);
    for(int i=0;i<n;i++) parent[i]=i;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        if(getParent(a)==getParent(b)){
            cout << i+1;
            return 0;
        }
        unionParent(a,b);
    }
    cout << 0;
    return 0;
}