#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    int a[]={3,2,0,2};
    int ans=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        int tmp=i;
        int ind=0;
        while(ind<4 && tmp>0){
            if(tmp%10==a[ind]) ind++;
            tmp/=10;
        }
        if(ind==4) ans++;
    }
    cout << ans;
    return 0;
}