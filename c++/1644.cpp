#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;
bool b[4000001];
vector<ll> a;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    a.push_back(0);
    cin >> n;
    for(int i=2;i<=n;i++){
        if(b[i]) continue;
        a.push_back(i);
        if(a.size()>1) a[a.size()-1]+=a[a.size()-2];
        for(int j=i;j<=n;j+=i) b[j]=1;
    }
    int l=1,r=1,res=0;
    while(max(l,r)<a.size()){
        ll c=a[r]-a[l-1];
        if(c<n) r++;
        else{
            if(c==n) res++;
            if(l==r) break;
            l++;
        }
    }
    cout << res;
    return 0;
}