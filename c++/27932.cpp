#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    for(int &t:h) cin >> t;
    auto solve=[&](int t) -> bool {
        int cnt=0;
        vector<bool> tired(n,1);
        for(int i=1;i<n;i++){
            if(abs(h[i]-h[i-1])>t){
                cnt+=tired[i]+tired[i-1];
                tired[i]=0;
                tired[i-1]=0;
            }
        }
        return cnt<=k;
    };
    int s=0,e=1e9;
    while(s<=e){
        int mid=(s+e)/2;
        if(solve(mid)) e=mid-1;
        else s=mid+1;
    }
    cout << s;
    return 0;
}