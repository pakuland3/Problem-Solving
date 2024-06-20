#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct line{
    int a,b,c,d;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("xor1.in","r",stdin);
    freopen("output.txt","w",stdout);
    vector<line> ans;
    int n,inn;
    cin >> n;
    int cnt=0;
    vector<vector<int>> a(n+1,vector<int> (n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        int st=1;
        for(int j=1;j<=n;j++){
            if(j>1 && !a[j][i] && a[j-1][i]){
                ans.push_back({i,i,st,j-1});
            }
            else if(!a[j][i]) st=j+1;
        }
    }
    cout << ans.size() << '\n';
    for(int i=0;i<ans.size();i++){
        cout << ans[i].a << ' ' << ans[i].b << ' ' << ans[i].c << ' ' << ans[i].d << '\n';
    }
    // cout << cnt;
    return 0;
}