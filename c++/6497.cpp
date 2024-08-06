#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct edge{
    int a,b,z;
};

int parent[200000];

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
    while(1){
        int m,n;
        cin >> m >> n;
        if(m==0) break;
        vector<edge> e(n);
        for(int i=0;i<m;i++) parent[i]=i;
        int ans=0,sum=0;
        for(edge &p:e){
            cin >> p.a >> p.b >> p.z;
            sum+=p.z;
        }
        sort(e.begin(),e.end(),[](edge &l, edge &r)->bool {return l.z<r.z;});
        for(int i=0;i<n;i++){
            edge cur=e[i];
            if(getParent(cur.a)==getParent(cur.b)) continue;
            ans+=cur.z;
            unionParent(cur.a,cur.b);
        }
        cout << sum-ans << '\n';
    }
    return 0;
}