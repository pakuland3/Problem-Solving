#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int l,k,c,cut;
int x[10000];

bool solve(int mid){
    int back=0;
    int cnt=0;
    bool vis[10001]={0,};
    while(back<l){
        
    }
    if(cnt>c) return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> l >> k >> c;
    for(int i=0;i<k;i++) cin >> x[i];
    sort(x,x+k);
    int s=1,e=l;
    while(s<=e){
        int mid=(s+e)/2;
        if(solve(mid)) s=mid+1;
        else e=mid-1;
    }
    cout << e << ' ' << cut;
    return 0;
}