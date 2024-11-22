#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n),b,c;
    for(int &t:a) cin >> t;
    for(int i=0;i<n;i++){
        if(a[i]==i+1) continue;
        auto j=find(a.begin()+i,a.end(),i+1);
        reverse(a.begin()+i,j+1);
        b.push_back(i+1);
        c.push_back(j-a.begin()+1);
    }
    cout << b.size() << '\n';
    for(int i=0;i<b.size();i++) cout << b[i] << ' ' << c[i] << '\n';
    return 0;
}