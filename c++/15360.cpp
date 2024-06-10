#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    vector<bool> a(n,0);
    for(int i=0;i<m;i++){
        int b;
        cin >> b;
        a[(--b)]=1;
        for(int j=1;j<=k;j++) for(int l:{b-j,b+j}){
            if(n<=l || l<0) continue;
            a[l]=1;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(!a[i]){ans++;i+=2*k;}
    }
    cout << ans;
    return 0;
}