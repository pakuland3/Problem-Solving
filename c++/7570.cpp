#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,t;
    int ans=1;
    cin >> n;
    vector<int> a(n),b(n,1);
    for(int i=0;i<n;i++){
        cin >> t;
        a[t-1]=i;
    }
    for(int i=1;i<n;i++) if(a[i]>a[i-1]){
        b[i]=b[i-1]+1;
        ans=max(ans,b[i]);
    }
    cout << n-ans;
    return 0;
}