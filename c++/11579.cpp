#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans=0;
        vector<vector<int>> a(n,vector<int> (n));
        for(vector<int> &p:a) for(int &b:p) cin >> b;
        vector<int> k(n),cur(n,0);
        for(int &p:k) cin >> p;
        for(int i=0;i<n;i++){
            int cnt=k[i]-cur[i];
            if(cnt<0) continue;
            ans+=cnt;
            for(int j=i;j<n;j++){
                cur[j]+=cnt*a[i][j];
            }
        }
        bool no=0;
        for(int i=0;i<n;i++){
            if(cur[i]!=k[i]){
                no=1;
                break;
            }
        }
        if(no) cout << "0\n";
        else cout << "1 " << ans << '\n';
    }
    return 0;
}