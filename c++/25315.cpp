#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct p{
    ll x,y;
    bool operator<=(p &a){
        if(x==a.x) return y<=a.y;
        return x<=a.x;
    }
};

struct l{
    p p1,p2;
    ll w;
};

int ccw(p a, p b, p c){
    ll t=a.x*b.y+b.x*c.y+c.x*a.y-b.x*a.y-c.x*b.y-a.x*c.y;
    if(t<0) return -1;
    if(t>0) return 1;
    return 0;
}

void s(l &a){
    if(a.p2<=a.p1) swap(a.p1,a.p2);
}

void input(l &a){
    cin >> a.p1.x >> a.p1.y >> a.p2.x >> a.p2.y >> a.w;
    s(a);
}

bool isIntersect(l a, l b){
    int t1=ccw(a.p1,a.p2,b.p1)*ccw(a.p1,a.p2,b.p2);
    int t2=ccw(b.p1,b.p2,a.p1)*ccw(b.p1,b.p2,a.p2);
    if(t1<=0 && t2<=0){
        if(t1==0 && t2==0) return a.p1<=b.p2 && b.p1<=a.p2;
        return 1;
    }
    return 0;
}

ll res=0;
int n;
l a,b;
bool vis[2500];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    vector<l> lines(n);
    for(int i=0;i<n;i++) input(lines[i]);
    sort(lines.begin(),lines.end(),[](l &a, l &b)->bool { return a.w<b.w; });
    for(int i=0;i<n;i++){
        ll cnt=1;
        vis[i]=1;
        for(int j=0;j<n;j++){
            if(vis[j]) continue;
            if(isIntersect(lines[i],lines[j])) cnt++;
        }
        res+=cnt*lines[i].w;
    }
    cout << res;
    return 0;
}