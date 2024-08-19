#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct a{
    int n,v;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,k,b;
    cin >> n >> k;
    deque<a> dq;
    for(int i=0;i<n;i++) for(int j=0;j<k;j++){
        cin >> b;
        dq.push_back({i+1,b});
    }
    while(dq.size()!=1){
        int v=dq.front().v%(dq.size()-1)!=0?dq.front().v%(dq.size()-1):dq.front().v;
        v--;
        dq.pop_front();
        while(v--){
            dq.push_back(dq.front());
            dq.pop_front();
        }
    }
    cout << dq.back().n << ' ' << dq.back().v;
    return 0;
}