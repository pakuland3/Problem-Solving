#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed; cout.precision(10);
    double x,y,d,t;
    cin >> x >> y >> d >> t;
    double dist=sqrt(x*x+y*y),ans=dist,tmp=dist;
    if(dist<t){cout << dist; return 0;}
    if(d>=dist){
        cout << min(ans,min(2*t,t+d-dist));
        return 0;
    }
    double cnt=0;
    if((dist/d)==floor(dist/d)) ans=min(ans,dist/d*t);
    while(1){
        if(tmp<d) break;
        if(1<tmp/d && tmp/d<2) ans=min(ans,min(t*cnt+2*t,t*cnt+tmp));
        tmp-=d;
        cnt++;
        if(tmp==0) break;
    }
    if(tmp!=0){
        ans=min(ans,min(t*cnt+2*t,t*cnt+tmp));
    }
    cout << ans;
    return 0;
}