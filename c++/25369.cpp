#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n,t;
int res[7];

void solve(int cnt, int &cc){
    if(cnt==n){
        if(cc>t){
            for(int i=0;i<n;i++) cout << res[i] << ' ';
            exit(0);
        }
        return;
    }
    for(int i=1;i<10;i++){
        cc*=i;
        res[cnt]=i;
        solve(cnt+1,cc);
        cc/=i;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> t;
    for(int i=1;i<n;i++){
        int tt;
        cin >> tt;
        t*=tt;
    }
    int cc=1;
    solve(0,cc);
    cout << -1;
    return 0;
}