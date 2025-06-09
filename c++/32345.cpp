#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc;
    cin >> tc;
    const int M=1000000007;
    char vowel[]={'a','e','i','o','u'};
    while(tc--){
        string a;
        cin >> a;
        reverse(a.begin(),a.end());
        vector<ll> d(a.length(),0);
        auto idx=[&](int c){
            for(int i=0;i<5;i++) if(a[c]==vowel[i]) return 1;
            return 0;
        };
        int ldx=-1;
        for(int i=0;i<a.length();i++){
            if(idx(i)){
                if(ldx==-1) d[i]=1;
                else d[i]=((i-ldx)*d[ldx])%M;
                ldx=i;
            }
        }
        cout << (ldx!=-1?d[ldx]:-1) << '\n';
    }
    return 0;
}