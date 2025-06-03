#include <bits/stdc++.h>
#define eps 1e-2
typedef long long ll;
using namespace std;

double t,a;

double d(double x, double y){
    return sqrt((x-t)*(x-t)+y*y);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        cin >> t >> a;
        a*=3.1415926535/180;
        t*=100;
        double cyc=42.5/tan(a);
        int cc=0;
        int cnt=0;
        double x=0,y=0;
        int flag=0;
        while(x<t+16){
            if(abs(d(x,y)-16)<.1){
                flag=1;
                break;
            }
            x=cnt*eps;
            if(x>(cc+1)*cyc) cc++;
            y=(cc&1?(cc+1)*cyc-x:x-cc*cyc)*tan(a)*((cc>>1)&1?1:-1);
            cnt++;
        }
        cout << (flag?"yes":"no") << '\n';
    }
    return 0;
}