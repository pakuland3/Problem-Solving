#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string T,P;
    getline(cin,T);
    getline(cin,P);
    vector<int> f(P.size());
    int j=0;
    for(int i=1;i<P.size();i++){
        while(j>0 && P[i]!=P[j]) j=f[j-1];
        if(P[i]==P[j]) f[i]=++j;
    }
    j=0;
    vector<int> ans;
    for(int i=0;i<T.size();i++){
        while(j>0 && T[i]!=P[j]) j=f[j-1];
        if(T[i]==P[j]) j++;
        if(j==P.size()){
            ans.push_back(i+2-P.size());
            j=f[j-1];
        }
    }
    cout << ans.size() << '\n';
    for(int t:ans) cout << t << ' ';
    return 0;
}