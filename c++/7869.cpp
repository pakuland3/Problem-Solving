#include <bits/stdc++.h>
#define PI 3.1415926535
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.precision(3);
    cout << fixed;
    double x1,y1,x2,y2,r1,r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    double ans;
    if(d>=r1+r2) ans=0;
    else if(d+min(r1,r2)<=max(r1,r2)) ans=PI*min(r1,r2)*min(r1,r2);
    else{
        double t1=2.0*acos((r1*r1+d*d-r2*r2)/2.0/r1/d);
        double t2=2.0*acos((r2*r2+d*d-r1*r1)/2.0/r2/d);
        double s1=r1*r1*t1/2.0-r1*r1*sin(t1)/2.0;
        double s2=r2*r2*t2/2.0-r2*r2*sin(t2)/2.0;
        ans=s1+s2;
    }
    ans=round(ans*1000)/1000;
    cout << ans;
    return 0;
}