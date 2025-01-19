#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int maxi=0;
    map<string,vector<int>> m;
    set<string> s;
    for(int i=0;i<n;i++){
        string a,d;
        int b,c;
        cin >> d >> a >> b >> c;
        if(s.find(d)!=s.end()) continue;
        s.insert(d);
        c--;
        if(m.find(a)==m.end()) m[a]=vector<int>(50001,0);
        for(int j=b;j<=c;j++){
            m[a][j]++;
            maxi=max(maxi,m[a][j]);
        }
    }
    vector<pair<string,pair<int,int>>> ans;
    for(auto it=m.begin();it!=m.end();it++){
        int s=-1,e;
        for(int i=1;i<=50000;i++){
            if(it->second[i]==maxi){
                s=i;
                while(it->second[i]==maxi) i++;
                e=i-1;
                break;
            }
        }
        if(s!=-1) ans.push_back({it->first,{s,e}});
    }
    sort(ans.begin(),ans.end());
    cout << ans[0].first << ' ' << ans[0].second.first << ' ' << ans[0].second.second+1;
    return 0;
}