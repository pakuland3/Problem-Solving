#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<int> s[2],d(n);
    s[0].resize(n); s[1].resize(n);
    for(int &t:s[0]) cin >> t;
    for(int &t:d) cin >> t;
    for(int i=0;i<k;i++){
        int f=i&1;
        int g=!f;
        for(int j=0;j<n;j++) s[g][d[j]-1]=s[f][j];
    }
    for(int i=0;i<n;i++) cout << s[k&1][i] << ' ';
    return 0;
}