#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,k;
    cin >> n >> k;
    string a,b;
    ll c,d;
    cin >> a >> c;
    cin >> b >> d;
    ll S=(c-1)*(a[0]==')' && a[a.length()-1]=='(');
    ll T=(d-1)*(b[0]==')' && b[b.length()-1]=='(');
    ll t=0;
    for(int i=1;i<a.length();i++) if(a[i]==')' && a[i-1]=='(') t++;
    S+=c*t;
    t=0;
    for(int i=1;i<b.length();i++) if(b[i]==')' && b[i-1]=='(') t++;
    T+=d*t;
    if(T>=k && S>=k) cout << n;
    else cout << min((S>=k?(S-k):0)/(k==T?1:k-T)+(S>=k),n);
    return 0;
}