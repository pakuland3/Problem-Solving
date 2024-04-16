#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll x0,n,tmp,i=1;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    unordered_map<ll, ll> um;
    set<ll> s;
    cin >> x0 >> n;
    if(x0%2==0) tmp=(x0/2)^6;
    else tmp=(x0*2)^6;
    s.insert(x0);
    um[x0]=0;
    while(s.find(tmp)==s.end()){
        um[tmp]=i++;
        s.insert(tmp);
        if(tmp%2==0) tmp=(tmp/2)^6;
        else tmp=(tmp*2)^6;
    }
    vector<ll> cyc;
    set<ll> cycs;
    cycs.insert(tmp);
    cyc.push_back(tmp);
    tmp=tmp%2?(2*tmp)^6:(tmp/2)^6;
    while(cycs.find(tmp)==cycs.end()){
        cycs.insert(tmp);
        if(tmp%2==0) tmp=(tmp/2)^6;
        else tmp=(tmp*2)^6;
    }
    if(s.size()>n){
        for(auto it=um.begin();it!=um.end();it++) if(it->second==n){cout << it->first; return 0;}
    }
    else{
        int ind=(n-s.size())%cyc.size();
        if(ind==0) cout << cyc[cyc.size()-1];
        else cout << cyc[ind-1];
    }
    return 0;
}