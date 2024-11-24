#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool sieve[500001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n;
    cin >> n;
    ll cnt=(n+1)/2-1;
    cout << (n-1+(n%2==0))*cnt/2 << '\n';
    cnt=sqrt(n);
    vector<int> divs;
    stack<int> st;
    for(int i=1;i<=cnt;i++){
        if(n%i==0){
            divs.push_back(i);
            if(i!=n/i) st.push(n/i);
        }
    }
    ll ans=0;
    while(!st.empty()){
        divs.push_back(st.top());
        st.pop();
    }
    for(int i=0;i<divs.size();i++) for(int j=i;j<divs.size();j++) ans+=binary_search(divs.begin(),divs.end(),divs[i]+divs[j]);
    cout << ans << '\n';
    for(int i=2;i<=cnt;i++){
        if(sieve[i]) continue;
        for(ll j=(ll)i*i;j<=n;j+=i) sieve[j]=1;
    }
    ans=0;
    for(int i=5;i<=n;i++) if(!sieve[i] && !sieve[i-2]) ans++;
    cout << ans;
    return 0;
}