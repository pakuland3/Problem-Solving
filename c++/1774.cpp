#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> parent;

struct pos{
    double x,y;
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
    cout.precision(2);
    cout << fixed;
    int n,m;
    double ans=0;
    cin >> n >> m;
    parent.resize(n);
    for(int i=0;i<n;i++) parent[i]=i;
    vector<pos> a(n);
    vector<pair<pair<int,int>,double>> distances(n*(n-1)/2);
    int ind=0;
    for(int i=0;i<n;i++){
        cin >> a[i].x >> a[i].y;
        for(int j=0;j<i;j++){
            distances[ind].first.first=i;
            distances[ind].first.second=j;
            distances[ind++].second=pow(a[i].x-a[j].x,2)+pow(a[i].y-a[j].y,2);
        }
    }
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b; a--; b--;
        unionParent(a,b);
    }
    sort(distances.begin(),distances.end(),[](auto l, auto r)->bool{
        return l.second<r.second;
    });
    for(auto &p:distances) if(getParent(p.first.first)!=getParent(p.first.second)){
        unionParent(p.first.first,p.first.second);
        ans+=sqrt(p.second);
    }
    cout << round(ans*100)/100;
    return 0;
}