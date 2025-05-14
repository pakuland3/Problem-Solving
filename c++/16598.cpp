#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,p;
    cin >> n >> p;
    int d[200000];
    for(int i=0;i<n;i++) cin >> d[i];
    int s=0;
    int ans=0;
    for(int e=0;e<n;e++){
        if(d[e]-d[s]+1-(e-s+1)>p) s++;
        ans=max(ans,p+e-s+1);
    }
    cout << ans;
    return 0;
}