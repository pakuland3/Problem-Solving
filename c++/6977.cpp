#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n,k;

void solve(int idx, int cnt, vector<string> &ans, string &a){
    if(cnt==k){
        ans.push_back(a);
        return;
    }
    if(idx>n-k+cnt) return;
    for(int i=idx;i<n;i++){
        a[i]='1';
        solve(i+1,cnt+1,ans,a);
        a[i]='0';
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        string a; for(int i=0;i<n;i++) a+='0';
        vector<string> ans;
        solve(0,0,ans,a);
        sort(ans.begin(),ans.end(),greater<string>());
        cout << "The bit patterns are\n";
        for(string &t:ans) cout << t << '\n';
        cout << '\n';
    }
    return 0;
}