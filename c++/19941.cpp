#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]!='P') continue;
        for(int j=max(0,i-k);j<=min(i+k,n-1);j++){
            if(i==j) continue;
            if(s[j]=='H'){
                ans++;
                s[j]='.';
                break;
            }
        }
    }
    cout << ans;
    return 0;
}