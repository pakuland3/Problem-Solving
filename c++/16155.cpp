#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct ab{
    int a=1,b=1;
};

void doDiv(int &a, int &b){
    int g=gcd(a,b);
    a/=g;
    b/=g;
    return;
}

void doSum(int &p, int &q, int &a, int &b){
    int g=gcd(q,b);
    int c=b/g;
    int d=q/g;
    q*=c;
    p*=c;
    a*=d;
    p+=a;
    doDiv(p,q);
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> x(n+1),h(n+1);
    vector<ab> til(n+1);
    int s,e,g,c,d;
    for(int i=0;i<=n;i++){
        cin >> x[i] >> h[i];
        if(i>0){
            til[i].a=h[i]-h[i-1];
            til[i].b=x[i]-x[i-1];
            doDiv(til[i].a,til[i].b);
        }
    }
    cin >> s >> e;
    int l=upper_bound(x.begin(),x.end(),s)-x.begin();
    int r=upper_bound(x.begin(),x.end(),e)-x.begin();
    if(l==r){
        cout << til[l].a;
        if(til[l].b!=1) cout << '/' << til[l].b;
    }
    else{
        int p=(x[l]-s)*til[l].a,q=til[l].b;
        l++;
        doDiv(p,q);
        // add p/q+(e-x[r-1])*til[r].a/til[r].b
        int c=(e-x[r-1])*til[r].a;
        int d=til[r].b;
        doSum(p,q,c,d);
        for(int i=l;i<r;i++){
            c=til[r].a*(x[i]-x[i-1]);
            d=til[r].b;
            doSum(p,q,c,d);
        }
        q*=(e-s);
        doDiv(p,q);
        cout << p;
        if(q!=1) cout << '/' << q;
    }
    return 0;
}