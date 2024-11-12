#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct p{
    double x,y,r;
};

double dis(p a, p b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double solve(p a, p b){
    double d=dis(a,b);
    double bot=2*d*a.r;
    double t=acos((d*d+a.r*a.r-b.r*b.r)/bot);
    double S1=a.r*a.r*t/2;
    double S2=a.r*a.r*sin(t)*cos(t);
    return S1-S2;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.precision(3);
    cout.fixed;
    p a,b;
    cin >> a.x >> a.y >> a.r >> b.x >> b.y >> b.r;
    if(a.r==0 || b.r==0 || dis(a,b)>=a.r+b.r){
        cout << 0;
        return 0;
    }
    double ans;
    if(a.r+dis(a,b)<=b.r) ans=a.r*a.r*3.14159265358979;
    else if(b.r+dis(a,b)<=a.r) ans=b.r*b.r*3.14159265358979;
    else ans=solve(a,b)+solve(b,a);
    ans=ans*10000;
    ll tmp=ans;
    if(tmp%10>4) tmp+=10;
    ans=tmp/10000;
    cout << ans; 
    return 0;
}