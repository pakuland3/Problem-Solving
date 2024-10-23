#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct poi{
    ll x,y;
};

int ccw(poi a, poi b, poi c){
    ll t=a.x*b.y+b.x*c.y+c.x*a.y-a.x*c.y-b.x*a.y-c.x*b.y;
    if(t<0) return -1;
    if(t>0) return 1;
    return t;
}

void doSwap(poi &a, poi &b){
    if(a.x==b.x && a.y<b.y) swap(a,b);
    if(b.x<a.x) swap(a,b);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    poi a,b,c,d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    doSwap(a,b);
    doSwap(c,d);
    if(ccw(a,b,c)*ccw(a,b,d)<0 && ccw(c,d,a)*ccw(c,d,b)<0) cout << 1;
    else cout << 0;
    return 0;
}