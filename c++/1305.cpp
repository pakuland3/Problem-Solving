#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int j=0;
    vector<int> f(s.size());
    for(int i=1;i<s.size();i++){
        while(j>0 && s[i]!=s[j]) j=f[j-1];
        if(s[i]==s[j]) f[i]=++j;
    }
    cout << n-f[s.size()-1];
    return 0;
}