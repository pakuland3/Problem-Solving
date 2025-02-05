#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,c;
    cin >> n >> c;
    vector<int> a(c),d(n+1,0),b(n+1);
    d[0]=1;
    for(int &t:a) cin >> t;
    for(int i=0;i<c;i++){
        fill(b.begin(),b.end(),0);
        for(int j=a[i];j<=n;j++){
            int t=0;
            int cnt=j/a[i];
            for(int k=1;k<=cnt;k++) b[j]+=d[j-k*a[i]];
        }
        for(int j=a[i];j<=n;j++) d[j]+=b[j];
    }
    cout << d[n];
    return 0;
}