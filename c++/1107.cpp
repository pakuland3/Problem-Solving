#include <bits/stdc++.h>
using namespace std;

int n,m,ans,sl;
string s;
vector<int> arr,nums;

void solve(int cnt,string l, bool b, int zerocnt){
    if(!b) ans=min(ans,n+1);
    else ans=min(ans,abs(stoi(l)-n)+cnt-zerocnt);
    if(cnt==7) return;
    for(int i=0;i<arr.size();i++){
        l+=arr[i]+'0';
        if(arr[i]==0 && !b) solve(cnt+1,l,0,zerocnt+1);
        else solve(cnt+1,l,1,zerocnt);
        l.erase(l.length()-1);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s >> m; n=stoi(s); ans=abs(n-100); sl=s.length();
    for(int i=0;i<m;i++){int inn; cin >> inn; arr.push_back(inn);} 
    if(s=="100"){cout << 0; return 0;}
    sort(arr.begin(),arr.end()); int s=0;
    for(int i=0;i<10;i++){
        if(s<arr.size() && i==arr[s]) s++;
        else arr.push_back(i);
    }
    for(int i=0;i<m;i++) arr.erase(arr.begin());
    solve(0,"",0,0);
    cout << ans;
    return 0;
}