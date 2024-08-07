#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,k;
    cin >> n >> m;
    unordered_map<string,int> um;
    vector<string> a(n);
    for(string &s:a) cin >> s;
    cin >> k;
    for(string &s:a){
        int cnt=0;
        for(int j=0;j<m;j++) if(s[j]=='0') cnt++;
        if(cnt>k) continue;
        if(k%2!=cnt%2) continue;
        if(um.find(s)!=um.end()) um[s]++;
        else um[s]=1;
    }
    int ans=0;
    for(auto &it:um) ans=max(ans,it.second);
    cout << ans;
    return 0;
}