#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int cnt[10];
vector<int> n;
string a("");
int length;

void solve(int c){
    if(c==length){
        n.push_back(stoi(a));
        return;
    }
    for(int i=0;i<10;i++){
        if(cnt[i]>0){
            a+=i+'0';
            cnt[i]--;
            solve(c+1);
            cnt[i]++;
            a.erase(a.length()-1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    length=s.length();
    for(int i=0;i<s.length();i++) cnt[s[i]-'0']++;
    solve(0);
    sort(n.begin(),n.end());
    int idx=lower_bound(n.begin(),n.end(),stoi(s))-n.begin();
    if(idx==n.size()-1) cout << 0;
    else cout << n[idx+1];
    return 0;
}