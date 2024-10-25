#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct frac{
    ll top,bottom;
};

struct p{
    ll x,y;
    bool operator<=(p &a){
        if(x==a.x) return y<=a.y;
        return x<=a.x;
    }
    bool operator==(p &a){ return (x==a.x && y==a.y); }
};

struct l{
    p p1,p2;
};

int ccw(p a, p b, p c){
    ll t=a.x*b.y+b.x*c.y+c.x*a.y-a.x*c.y-b.x*a.y-c.x*b.y;
    if(t>0) return 1;
    if(t<0) return -1;
    return t;
}

bool isIntersect(l a, l b){
    int t1=ccw(a.p1,a.p2,b.p1)*ccw(a.p1,a.p2,b.p2);
    int t2=ccw(b.p1,b.p2,a.p1)*ccw(b.p1,b.p2,a.p2);
    if(t1<=0 && t2<=0){
        if(t1==0 && t2==0){
            if(a.p1<=b.p2 && b.p1<=a.p2) return 1;
            else return 0;
        }
        else return 1;
    }
    return 0;
}

void s(l &a){ if(a.p2<=a.p1) swap(a.p1,a.p2); }

void input(l &a){
    cin >> a.p1.x >> a.p1.y >> a.p2.x >> a.p2.y;
    s(a);
}

void printp(p a){ cout << a.x << ' ' << a.y; }

bool isVertical(l a){ return a.p1.x==a.p2.x; }

bool isHorizontal(l a){ return a.p1.y==a.p2.y; }

void doGCD(frac &a){
    ll n=gcd(abs(a.top),abs(a.bottom));
    if(n==0) return;
    a.top/=n;
    a.bottom/=n;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    l a,b;
    cout.precision(10);
    cout << fixed;
    input(a);
    input(b);
    bool s=isIntersect(a,b);
    if(s){
        cout << "1\n";
        if(a.p1==b.p2) printp(a.p1);
        else if(a.p2==b.p1) printp(a.p2);
        else if(isVertical(a) && isHorizontal(b)) cout << a.p1.x << ' ' << b.p1.y;
        else if(isVertical(b) && isHorizontal(a)) cout << b.p1.x << ' ' << a.p1.y;
        else if(!(isVertical(a) && isVertical(b)) && !(isHorizontal(a) && isHorizontal(b))){
            frac aa,bb,ap,bp,x,y;
            aa.top=a.p1.y-a.p2.y,aa.bottom=a.p1.x-a.p2.x;
            doGCD(aa);
            bb.top=(a.p1.x-a.p2.x)*a.p1.y-(a.p1.y-a.p2.y)*a.p1.x,bb.bottom=a.p1.x-a.p2.x;
            doGCD(bb);
            ap.top=b.p1.y-b.p2.y,ap.bottom=b.p1.x-b.p2.x;
            doGCD(ap);
            bp.top=(b.p1.x-b.p2.x)*b.p1.y-(b.p1.y-b.p2.y)*b.p1.x,bp.bottom=b.p1.x-b.p2.x;
            doGCD(bp);
            bool c1=aa.top*ap.bottom==ap.top*aa.bottom;
            bool c2=bb.top*bp.bottom==bp.top*bb.bottom;
            if(!(c1 && c2)){
                x.top=aa.bottom*ap.bottom*(bp.bottom*bb.top-bb.bottom*bp.top);
                x.top*=-1;
                x.bottom=bb.bottom*bp.bottom*(ap.bottom*aa.top-aa.bottom*ap.top);
                doGCD(x);
                y.top=aa.top*x.top*bb.bottom+bb.top*aa.bottom*x.bottom;
                y.bottom=aa.bottom*x.bottom*bb.bottom;
                doGCD(y);
                cout << x.top/(double)x.bottom << ' ' << y.top/(double)y.bottom;
            }
        }
    }
    else cout << 0;
    return 0;
}