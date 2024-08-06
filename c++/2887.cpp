#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct poi{
    int x,y,z,id;
};

struct edge{
    int a,b;
    ll cost;
};

ll getDis(poi &l, poi &r){
    return min(min(abs(l.x-r.x),abs(l.y-r.y)),abs(l.z-r.z));
}

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
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,id=0;
    cin >> n;
    vector<poi> a(n);
    parent.resize(n);
    for(int i=0;i<n;i++) parent[i]=i;
    vector<edge> e;
    for(poi &p:a){
        cin >> p.x >> p.y >> p.z;
        p.id=id++;
    }
    sort(a.begin(),a.end(),[](poi &l, poi &r)->bool {return l.x<r.x;});
    for(int i=1;i<n;i++) e.push_back({a[i].id,a[i-1].id,getDis(a[i],a[i-1])});
    sort(a.begin(),a.end(),[](poi &l, poi &r)->bool {return l.y<r.y;});
    for(int i=1;i<n;i++) e.push_back({a[i].id,a[i-1].id,getDis(a[i],a[i-1])});
    sort(a.begin(),a.end(),[](poi &l, poi &r)->bool {return l.z<r.z;});
    for(int i=1;i<n;i++) e.push_back({a[i].id,a[i-1].id,getDis(a[i],a[i-1])});
    sort(e.begin(),e.end(),[](edge &l, edge &r)->bool {return l.cost<r.cost;});
    ll ans=0;
    for(int i=0;i<e.size();i++){
        edge p=e[i];
        if(getParent(p.a)==getParent(p.b)) continue;
        unionParent(p.a,p.b);
        ans+=p.cost;
    }
    cout << ans;
    return 0;
}