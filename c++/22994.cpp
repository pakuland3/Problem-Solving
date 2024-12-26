#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    int rn=0,rm=0;
    vector<string> a(n);
    vector<vector<int>> b(n,vector<int>(m,0)),c(b);
    for(string &t:a) cin >> t;
    for(int i=0;i<n;i++){
        unordered_set<int> s;
        for(int j=0;j<m;j++){
            b[i][j]=(j!=0?(a[i][j]==a[i][j-1]?b[i][j-1]+1:1):1);
            if(j!=0 && a[i][j]!=a[i][j-1] && s.find(b[i][j-1])==s.end()) s.insert(b[i][j-1]);
        }
        s.insert(b[i][m-1]);
        for(auto it=s.begin();it!=s.end();it++) rm=gcd(rm,*it);
    }
    for(int i=0;i<m;i++){
        unordered_set<int> s;
        for(int j=0;j<n;j++){
            c[j][i]=(j!=0?(a[j][i]==a[j-1][i]?c[j-1][i]+1:1):1);
            if(j!=0 && a[j][i]!=a[j-1][i] && s.find(c[j-1][i])==s.end()) s.insert(c[j-1][i]);
        }
        s.insert(c[n-1][i]);
        for(auto it=s.begin();it!=s.end();it++) rn=gcd(rn,*it);
    }
    if(rn==0) rn=n;
    if(rm==0) rm=m;
    cout << n/rn << ' ' << m/rm << '\n';
    for(int i=0;i<n;i+=rn){
        for(int j=0;j<m;j+=rm) cout << a[i][j];
        cout << '\n';
    }
    return 0;
}