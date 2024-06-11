#include <bits/stdc++.h>
#define cost first
#define city second
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout.precision(7);
    cout << fixed;
    int t;
    cin >> t;
    while(t--){
        int n,qq;
        cin >> n >> qq;
        vector<pair<double,double>> h(n);
        vector<vector<pair<int,double>>> graph(n);
        vector<double> d(n,(double)1e12);
        vector<int> c(n);
        for(auto &p:h) cin >> p.first >> p.second;
        int tmp;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++){
            cin >> tmp;
            if(i+1==j) c[i]=tmp;
        }
        cin >> tmp >> tmp;
        for(int i=0;i<n-1;i++){
            double dis=0;
            for(int j=i;j<n-1;j++){
                dis+=c[j];
                if(h[i].first>=dis) graph[i].push_back({j+1,dis/h[i].second});
                else break;
            }
        }
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
        pq.push({0,0});
        d[0]=0;
        while(!pq.empty()){
            pair<double,int> now=pq.top();
            pq.pop();
            for(int i=0;i<graph[now.city].size();i++){
                double addCost=now.cost+graph[now.city][i].second;
                if(d[graph[now.city][i].first]>=addCost){
                    d[graph[now.city][i].first]=addCost;
                    pq.push({addCost,graph[now.city][i].first});
                }
            }
        }
        cout << "Case #" << t+1 << ": " << d[n-1] << '\n';
    }
    return 0;
}