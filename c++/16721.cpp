#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int parent[5000];

int getParent(int x){
    if(x==parent[x]) return x;
    return parent[x]=getParent(parent[x]);
}

void unionParent(int a, int b){
    a=getParent(a);
    b=getParent(b);
    if(a>b) parent[a]=b;
    else parent[b]=a;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    char c;
    cin >> n;
    for(int i=0;i<n;i++) parent[i]=i;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        cin >> c;
        if(j<=i) continue;
        if(c=='+') unionParent(i,j); 
    }
    int m,a,b;
    cin >> m;
    while(m--){
        cin >> a >> b;
        if(getParent(a)==getParent(b)) cout << "+\n";
        else cout << "-\n";
    }
    return 0;
}