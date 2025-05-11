#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &t:a) cin >> t;
    sort(a.begin(),a.end());
    vector<pair<int,int>> b;
    vector<int> c(n,1);
    if(n==1){
        cout << 4;
        return 0;
    }
    for(int i=1;i<n;i++) if(a[i]==a[i-1]+1){
        c[i]=c[i-1]+1;
        c[i-1]=0;
    }
    for(int i=0;i<n;i++) if(c[i]) b.push_back({a[i],c[i]});
    int ans=4;
    for(int i=0;i<min(5,(int)b.size());i++){
        for(int j=0;j<b.size()-i;j++){
            int res=0;
            for(int l=j+1;l<j+i+1;l++) res+=(b[l].first-b[l].second+1)-b[l-1].first-1;
            int s=0;
            for(int l=j;l<j+i+1;l++) s+=b[l].second;
            if(res+s>4) ans=min(ans,res);
            else ans=min(ans,5-res-s);
        }
    }
    cout << ans;
    return 0;
}