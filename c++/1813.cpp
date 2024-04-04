#include <bits/stdc++.h>
using namespace std;

int n,tmp,ans=-1;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; vector<int> cnt(n+1,0);
    for(int i=0;i<n;i++){
        cin >> tmp;
        if(tmp>n) continue;
        cnt[tmp]++;
    }
    for(int i=0;i<=n;i++){
        if(cnt[i]==i) ans=i;
    }
    cout << ans;
    return 0;
}