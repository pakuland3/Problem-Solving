#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,k;
    cin >> n >> k;
    ll s=1,e=k,c=0;
    while(s<=e){
        ll mid=(s+e)/2;
        c=0;
        for(int i=1;i<=n;i++) c+=min(n,mid/(ll)i);
        if(c>=k) e=mid-1;
        else s=mid+1;
    }
    cout << s;
    return 0;
}