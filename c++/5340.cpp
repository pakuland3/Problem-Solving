#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> ans;
    for(int i=0;i<6;i++){
        string a;
        getline(cin,a);
        int cnt=a.length();
        if(a[a.length()-1]==' ') cnt--;
        ans.push_back(cnt);
    }
    cout << "Latitude " << ans[0] << ':' << ans[1] << ':' << ans[2] << '\n';
    cout << "Longitude " << ans[3] << ':' << ans[4] << ':' << ans[5] << '\n';
    return 0;
}