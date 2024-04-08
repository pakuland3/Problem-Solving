#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,k,a,b,ans=0; cin >> n >> k >> a;vector<int> arr(n-1);
    for(int i=0;i<n-1;i++){
        cin >> b; arr[i]=b-a;
        a=b;
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-k;i++) ans+=arr[i];
    cout << ans;
}