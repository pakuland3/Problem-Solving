#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int fastpow(int a, int b){
    if(b==0 || b==1) return (b&1?a:1);
    int t=fastpow(a,b/2);
    return t*t*(b&1?a:1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc;
    cin >> tc;
    for(int tt=0;tt<tc;tt++){
        int n;
        cin >> n;
        auto solve=[&](){
            for(int i=2;;i++){
                int t=(fastpow(i,1)-1)/(i-1);
                for(int j=1;t<=n;j++,t=(fastpow(i,j)-1)/(i-1)){
                    if(t==n) return i;
                }
            }
        };
        cout << "Case #" << tt+1 << ": " << solve() << '\n';
    }
    return 0;
}