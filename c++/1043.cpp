#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n,m,ans=0,parent[51],tmp,cnt,s=0,backN;

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
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    vector<int> vec(m);
    for(int i=0;i<=n;i++) parent[i]=i;
    cin >> cnt;
    for(int i=0;i<cnt;i++){
        cin >> tmp;
        unionParent(0,tmp);
    }
    while(m--){
        cin >> cnt;
        for(int i=0;i<cnt;i++){
            cin >> vec[s];
            if(i!=0) unionParent(backN,vec[s]);
            backN=vec[s];
        }
        s++;
    }
    for(int cur:vec){
        if(getParent(cur)!=0) ans++;
    }
    cout << ans;
    return 0;
}