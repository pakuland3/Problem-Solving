#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll m2=101,m3=301;
ll n,a,b,c,d,e,f;

void g(ll v){
    m2=min(m2,v);
}

void h(ll v){
    m3=min(m3,v);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> a >> b >> c >> d >> e >> f;
    g(a+b); g(a+c); g(a+e); g(a+d); g(b+c); g(b+f); g(b+d); g(c+f); g(c+e); g(d+e); g(d+f); g(e+f);
    h(a+b+d); h(a+e+d); h(a+c+e); h(a+b+c); h(b+d+f); h(b+f+c); h(c+e+f); h(d+e+f);
    // if(n==1) cout << a+b+c+d+e+f;
    // else if(n==2) cout << m3*8;
    // else cout << 8*(n-2)*m2+4*m3+((n-2)*(n-2)*(n-2)+6*(n-2))*min(a,min(b,min(c,min(d,min(e,f)))));
    if(n==1) cout << a+b+c+d+e+f-max(a,max(b,max(c,max(d,max(e,f)))));
    else if(n==2) cout << 4*m2+4*m3;
    else cout << 4*m3+4*m2*(2*n-3)+min(a,min(b,min(c,min(d,min(e,f)))))*((n-2)*(n-2)+4*(n-1)*(n-2));
    return 0;
}