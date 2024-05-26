#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,k,t,p,ans=0,d=0;
    cin >> n >> k;
    cin >> t;
    for(int i=1;i<n;i++){cin >> p; ans+=p-t; if(p!=t) d++;}
    cout << ans << ' ' << d;
    return 0;
}