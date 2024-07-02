#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin >> m >> n;
    vector<int> ans;
    vector<char> a(16);
    for(int i=0;i<10;i++) a[i]=i+'0';
    for(int i=10;i<16;i++) a[i]=i-10+'A';
    while(m>=n){
        ans.push_back(m%n);
        m/=n;
    }
    ans.push_back(m);
    reverse(ans.begin(),ans.end());
    for(int &t:ans) cout << a[t];
    return 0;
}