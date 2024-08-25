#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int h,n,q;
    cin >> h >> n >> q;
    ll a,s=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        cin >> a;
        pq.push(a);
        s+=a;
    }
    for(int i=0;i<q+1;i++){
        if(i!=0){
            cin >> a;
            s+=a;
            pq.push(a);
        }
        while(s-pq.top()>=h){
            s-=pq.top();
            pq.pop();
        }
        if(s<h) cout << "-1\n";
        else cout << pq.size() << '\n';
    }
    return 0;
}