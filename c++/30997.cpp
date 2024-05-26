#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,a,b,c,k;
    ll m;
    cin >> n >> m >> k;
    vector<ll> ct(n,0);
    for(int i=1;i<m;i++){
        cin >> a >> b >> c;
        ct[--a]++; ct[--b]++; ct[--c]++;
    }
    ll f=0,g=1;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int p=j+1;p<n;p++){
                ll d=3ll*m-(ct[i]+ct[j]+ct[p]+3ll),e=3ll*m,div;
                for(int h=1;h<k;h++){
                    d*=3ll*m-(ct[i]+ct[j]+ct[p]+3ll);
                    e*=3ll*m;
                }
                d*=ct[i]+ct[j]+ct[p]+3ll;
                e*=3ll*m;
                div=gcd(d,e);
                d/=div; e/=div;
                if(f*e<d*g){
                    f=d;
                    g=e;
                    a=i;
                    b=j;
                    c=p;
                }
            }
        }
    }
    cout << f << ' ' << g << '\n';
    cout << a+1 << ' ' << b+1 << ' ' << c+1;
    return 0;
}