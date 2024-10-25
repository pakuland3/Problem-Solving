#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct poi{
    ll x,y;
    bool operator<=(poi &a){
        if(x==a.x) return y<=a.y;
        return x<=a.x;
    }
};

int ccw(poi a, poi b, poi c){
    ll t=a.x*b.y+b.x*c.y+c.x*a.y-a.x*c.y-b.x*a.y-c.x*b.y;
    if(t<0) return -1;
    if(t>0) return 1;
    return t;
}

void i(poi &a){ cin >> a.x >> a.y; }

void s(poi &a, poi &b){
    if(b<=a) swap(a,b);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    poi a,b,c,d;
    i(a); i(b); i(c); i(d);
    s(a,b); s(c,d);
    int t1=ccw(a,b,c),t2=ccw(a,b,d),t3=ccw(c,d,a),t4=ccw(c,d,b);
    if(t1*t2<=0 && t3*t4<=0){
        if(t1*t2==0 && t3*t4==0) cout << (c<=b && a<=d);
        else cout << 1;
    }
    else cout << 0;
    return 0;
}