#include <bits/stdc++.h>
using namespace std;

int n,m,s=0,ans;
vector<int> arr;

void solve(int cnt, string l){
    if(cnt!=0){
        ans=min(ans,cnt+abs(stoi(l)-n));
        if(l[0]=='0') return;
    }
    if(cnt==6) return;
    for(int i=0;i<arr.size();i++){
        l+=arr[i]+'0';
        solve(cnt+1,l);
        l.erase(l.length()-1);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m; ans=abs(100-n);
    for(int i=0;i<m;i++){int inn; cin >> inn; arr.push_back(inn);}sort(arr.begin(),arr.end());
    for(int i=0;i<10;i++){
        if(s<arr.size() && i==arr[s]) s++;
        else arr.push_back(i);
    }
    for(int i=0;i<m;i++) arr.erase(arr.begin());
    solve(0,"");
    cout << ans;
    return 0;
}