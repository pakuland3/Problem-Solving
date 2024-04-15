#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,b,tmp;
    cin >> n >> tmp; b=tmp;
    vector<bool> ck(n+1,0);
    vector<int> ind(n+1,-1);
    vector<int> ans;
    ind[b]=0;
    for(int i=1;i<n;i++){
        cin >> tmp;
        if(tmp==b){
            if(!ck[b]){ck[b]=1; ans.push_back(b);} 
        }
        else{
            b=tmp;
            if(ind[tmp]!=-1 && i-ind[tmp]==2 && !ck[b]){
                ck[tmp]=1; ans.push_back(tmp);
            }
        }
        ind[tmp]=i;
    }
    if(ans.size()==0) cout << "-1\n";
    else{sort(ans.begin(),ans.end()); for(int o:ans) cout << o << ' '; cout << '\n';}
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}