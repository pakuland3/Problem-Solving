#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.precision(7);
    cout << fixed;
    int n,a;
    cin >> n;
    priority_queue<double,vector<double>,greater<double>> pq;
    for(int i=0;i<n;i++){
        cin >> a;
        pq.push(a);
    }
    while(pq.size()!=1){
        double now=pq.top();
        pq.pop();
        now=(now+pq.top())/2;
        pq.pop();
        pq.push(now);
    }
    cout << pq.top();
    return 0;
}