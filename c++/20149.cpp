#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct p{
    ll x,y;
    bool operator<=(p &a){
        if(x==a.x) return y<=a.y;
        return x<=a.x;
    }
    bool operator==(p &a){
        return x==a.x && y==a.y;
    }
};

struct l{
    p p1,p2;
};

int ccw(p a, p b, p c){
    ll t=a.x*b.y+b.x*c.y+c.x*a.y-a.x*c.y-b.x*a.y-c.x*b.y;
    if(t>0) return 1;
    if(t<0) return -1;
    return 0;
}

int isIntersect(l a, l b){
    int t1=ccw(a.p1,a.p2,b.p1)*ccw(a.p1,a.p2,b.p2);
    int t2=ccw(b.p1,b.p2,a.p1)*ccw(b.p1,b.p2,a.p2);
    if(t1<=0 && t2<=0){
        if(t1==0 && t2==0){
            if(a.p1<=b.p2 && b.p1<=a.p2) return 2;
            return 0;
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

bool h(l &a){
    return a.p1.y==a.p2.y;
}

bool v(l &a){
    return a.p1.x==a.p2.x; 
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.precision(10);
    cout << fixed;
    l a,b;
    input(a); input(b);
    int sign=isIntersect(a,b);
    if(sign){
        cout << "1\n";
        ll ab=(a.p1.x-a.p2.x)*(b.p1.y-b.p2.y)-(a.p1.y-a.p2.y)*(b.p1.x-b.p2.x);
        if(a.p2==b.p1) cout << a.p2.x << ' ' << a.p2.y;
        else if(a.p2==b.p2){
            if(!((h(a) && h(b)) || (v(a) && v(b))) && ab!=0) cout << a.p2.x << ' ' << a.p2.y;
        }
        else if(a.p1==b.p2) cout << a.p1.x << ' ' << a.p1.y;
        else if(a.p1==b.p1){
            if(!((h(a) && h(b)) || (v(a) && v(b))) && ab!=0) cout << a.p1.x << ' ' << a.p1.y;
        }
        if(sign==2) return 0;
        ll xt=(a.p1.x*a.p2.y-a.p1.y*a.p2.x)*(b.p1.x-b.p2.x)-(a.p1.x-a.p2.x)*(b.p1.x*b.p2.y-b.p1.y*b.p2.x),yt=(a.p1.x*a.p2.y-a.p1.y*a.p2.x)*(b.p1.y-b.p2.y)-(a.p1.y-a.p2.y)*(b.p1.x*b.p2.y-b.p1.y*b.p2.x);
        cout << xt/(double)ab << ' ' << yt/(double)ab;
    }
    else cout << 0;
}