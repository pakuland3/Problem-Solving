#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> a;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,k,m;
    cin >> n >> k >> m;
    for(int i=0;i<n;i++){
        ll l;
        cin >> l;
        if(l<=k) continue;
        if(l<2*k) a.push_back(l-k);
        else a.push_back(l-2*k);
    }
    int s=1,e=1e9;
    while(s<=e){
        int mid=(s+e)/2;
        ll cnt=0;
        for(int &t:a) cnt+=t/mid;
        if(cnt>=m) s=mid+1;
        else e=mid-1;
    }
    cout << (e==0?-1:e);
    return 0;
}