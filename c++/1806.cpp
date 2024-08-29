#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n,s,a[100001];
int l=1,r=1;
int ans=100001;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> s;
    for(int i=1;i<=n;i++){ cin >> a[i]; a[i]+=a[i-1]; }
    while(max(l,r)<=n){
        int c=a[r]-a[l-1];
        if(c<s) r++;
        else{
            ans=min(ans,r-l+1);
            if(l==r) break;
            l++;
        }
    }
    if(ans==100001) cout << 0;
    else cout << ans;
    return 0;
}