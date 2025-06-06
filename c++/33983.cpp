#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> hpre(n+2),hsuf(n+2),opre(n+2),osuf(n+2);
    string s;
    cin >> s;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='H') hpre[i]=1;
        if(s[i-1]=='O') opre[i]=1;
        if(s[s.length()-i]=='H') hsuf[s.length()-i+1]=1;
        if(s[s.length()-i]=='O') osuf[s.length()-i+1]=1;
        hpre[i]+=hpre[i-1];
        opre[i]+=opre[i-1];
        hsuf[s.length()-i+1]+=hsuf[s.length()-i+2];
        osuf[s.length()-i+1]+=osuf[s.length()-i+2];
    }
    if(hpre[n]!=2*opre[n]){
        cout << "mix";
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(s[i-1]=='O' && (hpre[i]<opre[i] || hsuf[i]<osuf[i])){
            cout << "mix";
            return 0;
        }
    }
    cout << "pure";
    return 0;
}