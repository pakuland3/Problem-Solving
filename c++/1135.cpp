#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<int>> child;
vector<int> t;

void solve(int node){
    if(child[node].size()==0){
        t[node]=0;
        return;
    }
    for(int i=0;i<child[node].size();i++){
        solve(child[node][i]);
        child[node][i]=t[child[node][i]];
    }
    sort(child[node].begin(),child[node].end(),greater<int>());
    for(int i=0;i<child[node].size();i++){
        t[node]=max(t[node],i+1+child[node][i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    child.resize(n);
    t.resize(n);
    int a;
    cin >> a;
    for(int i=1;i<n;i++){
        cin >> a;
        child[a].push_back(i);
    }
    solve(0);
    cout << t[0];
    return 0;
}