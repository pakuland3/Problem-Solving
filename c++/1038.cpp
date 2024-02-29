#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> v;

void dfs(string s){
    int x=s[s.length()-1]-'0';
    v.push_back(stoll(s));
    for(int i=0;i<10;i++){
        if(x<=i) break;
        dfs(s+to_string(i));
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0;i<10;i++) dfs(to_string(i));
    sort(v.begin(),v.end());
    if(v.size()<n+1) cout << -1;
    else cout << v[n];
    return 0;
}