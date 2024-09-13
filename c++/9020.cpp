#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> p;
bool s[10001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);    
    for(int i=2;i<=10000;i++){
        if(s[i]) continue;
        p.push_back(i);
        for(int j=2*i;j<=10000;j+=i) s[j]=1;
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int idx=0;
        int ans,nn=n/2;
        while(p[idx]<=nn){
            if(binary_search(p.begin(),p.end(),n-p[idx])) ans=p[idx];
            idx++;
        }
        cout << ans << ' ' << n-ans << '\n';
    }
    return 0;
}