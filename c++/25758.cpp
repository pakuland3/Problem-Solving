#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> a(26,vector<int> (26,0));
    while(n--){
        string b;
        cin >> b;
        a[b[0]-'A'][b[1]-'A']++;
    }
    vector<pair<int, int>> c;
    vector<bool> ans(26,0);
    for(int i=0;i<26;i++) for(int j=0;j<26;j++) if(a[i][j]>0){
        for(int k=0;k<min(a[i][j],2);k++) c.push_back({i,j});
    }
    for(int i=0;i<c.size();i++) for(int j=i+1;j<c.size();j++){
        if(c[i].first>c[j].second) ans[c[i].first]=1;
        else ans[c[j].second]=1;
        if(c[i].second>c[j].first) ans[c[i].second]=1;
        else ans[c[j].first]=1;
    }
    int cnt=0;
    for(int i=0;i<26;i++) if(ans[i]) cnt++;
    cout << cnt << '\n';
    for(int i=0;i<26;i++) if(ans[i]) cout << (char)(i+'A') << ' ';
    return 0;
}