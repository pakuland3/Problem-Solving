#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int parent[3000];
int cnt[3000];

struct p{
    ll x,y;
    bool operator<=(p &a){
        if(x==a.x) return y<=a.y;
        return x<=a.x;
    }
};

struct l{
    p p1,p2;
};

int ccw(p a, p b, p c){
    ll t=a.x*b.y+b.x*c.y+c.x*a.y-a.x*c.y-b.x*a.y-c.x*b.y;
    if(t<0) return -1;
    if(t>0) return 1;
    return t;
}

void s(l &a){ if(a.p2<=a.p1) swap(a.p1,a.p2); }

void input(l &a){
    cin >> a.p1.x >> a.p1.y >> a.p2.x >> a.p2.y;
    s(a);
}

bool isIntersect(l a, l b){
    int t1=ccw(a.p1,a.p2,b.p1)*ccw(a.p1,a.p2,b.p2);
    int t2=ccw(b.p1,b.p2,a.p1)*ccw(b.p1,b.p2,a.p2);
    if(t1<=0 && t2<=0){
        if(t1==0 && t2==0) return (a.p1<=b.p2 && b.p1<=a.p2);
        return 1;
    }
    return 0;
}

int getParent(int x){
    if(parent[x]==x) return x;
    return parent[x]=getParent(parent[x]);
}

void unionParent(int a, int b){
    a=getParent(a);
    b=getParent(b);
    if(a==b) return;
    if(a<b){
        parent[b]=a;
        cnt[a]+=cnt[b];
    }
    else{
        parent[a]=b;
        cnt[b]+=cnt[a];
    }
}

l lines[3000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        parent[i]=i;
        cnt[i]=1;
    }
    for(int i=0;i<n;i++){
        input(lines[i]);
        for(int j=0;j<i;j++){
            if(isIntersect(lines[i],lines[j])) unionParent(i,j);
        }
    }
    unordered_set<int> um;
    int maxi=1;
    for(int i=0;i<n;i++){
        int t=getParent(i);
        maxi=max(maxi,cnt[t]);
        if(um.find(t)==um.end()) um.insert(t);
    }
    cout << um.size() << '\n' << maxi;
    return 0;
}