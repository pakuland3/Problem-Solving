#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<int> a;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        if(t==1) a.push_back(i);
    }
    if(a.size()<k){
        cout << -1;
        return 0;
    }
    int ans=n;
    for(int i=k-1;i<a.size();i++) ans=min(a[i]-a[i+1-k]+1,ans);
    cout << ans;
    return 0;
}