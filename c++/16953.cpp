#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll A,B;
queue<pair<ll, ll>> q;

int main(){
    cin >> A >> B;
    q.push({A,1});
    while(!q.empty()){
        pair<ll, ll> x=q.front();
        if(x.first==B) break;
        q.pop();
        if(2*x.first<=B) q.push({2*x.first, x.second+1});
        if(10*x.first+1<=B) q.push({10*x.first+1, x.second+1});
    }
    if(!q.empty()) cout << q.front().second;
    else cout << -1;
}