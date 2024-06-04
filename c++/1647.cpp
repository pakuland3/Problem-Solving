#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> parent;

struct edg{
    int cost;
    int start;
    int ed;
};

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
    int v,e,cnt=1;
    cin >> v >> e;
    parent.resize(v+1); for(int i=1;i<=v;i++) parent[i]=i;
    vector<edg> edgs(e);
    for(edg &t:edgs) cin >> t.start >> t.ed >> t.cost;
    sort(edgs.begin(),edgs.end(),[](edg l, edg r)->bool{
        return l.cost<r.cost;
    });
    unionParent(edgs[0].start,edgs[0].ed);
    if(v==2){cout << 0; return 0;}
    int ans=edgs[0].cost;
    for(int i=1;i<e;i++){
        if(getParent(edgs[i].start)!=getParent(edgs[i].ed)){
            cnt++;
            if(cnt==v-1){
                cout << ans;
                return 0;
            }
            ans+=edgs[i].cost;
            unionParent(edgs[i].start,edgs[i].ed);
        }
    }
    cout << ans;
    return 0;
}