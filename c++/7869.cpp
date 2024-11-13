#include <bits/stdc++.h>
#define PI 3.14159265358979
typedef long long ll;
typedef long double ld;
using namespace std;

struct p{
    ld x,y,r;
};

ld dis(p a, p b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

ld theta(p a, p b){
    ld d=dis(a,b);
    ld bot=(ld)2*d*a.r;
    ld t=acos((d*d+a.r*a.r-b.r*b.r)/bot);
    return t;
}

ld solve(p a, p b){
    ld t=theta(a,b);
    ld S1=a.r*a.r*t/(ld)2;
    ld S2=a.r*a.r*sin(t)*cos(t);
    return S1-S2;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.precision(3);
    cout << fixed;
    p a,b;
    cin >> a.x >> a.y >> a.r >> b.x >> b.y >> b.r;
    ld d=dis(a,b);
    if(a.r==0 || b.r==0 || d>=a.r+b.r){
        cout << 0;
        return 0;
    }
    ld ans=-1;
    if(d<b.r){
        ld t=theta(b,a);
        ans=b.r*a.r/(ld)2+b.r*b.r*(t-sin(t));
    }
    else if(d<a.r){
        ld t=theta(b,a);
        ans=b.r*a.r/(ld)2+a.r*a.r*(t-sin(t));
    }
    else if(a.r+d<=b.r) ans=a.r*a.r*PI;
    else if(b.r+d<=a.r) ans=b.r*b.r*PI;
    else ans=solve(a,b)+solve(b,a);
    ans*=1000;
    ans=round(ans);
    ans/=1000;
    cout << ans;
    return 0;
}