#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct poi{
    double x,y;
};

struct g{
    int a,b,c;
};

struct info{
    bool done=0;
    int c;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<bool> done(3*n,0);
    vector<info> isCon(3*n);
    vector<g> ans;
    vector<poi> p(3*n);
    priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>> pq;
    for(int i=0;i<3*n;i++){
        double x,y;
        cin >> x >> y;
        for(int j=0;j<i;j++) pq.push({pow(p[j].x-x,2)+pow(p[j].y-y,2),{i,j}});
    }
    while(!pq.empty()){
        int a=pq.top().second.first;
        int b=pq.top().second.second;
        pq.pop();
        if(done[a] || done[b]) continue;
        if(isCon[a].done && isCon[b].done) continue;
        if(isCon[a].done){
            ans.push_back({a,b,isCon[a].c});
            done[a]=1;
            done[b]=1;
            done[isCon[a].c]=1;
        }
        else if(isCon[b].done){
            ans.push_back({a,b,isCon[b].c});
            done[a]=1;
            done[b]=1;
            done[isCon[b].c]=1;
        }
        else{
            isCon[a].done=1;
            isCon[b].done=1;
            isCon[a].c=b;
            isCon[b].c=a;
        }
    }
    for(auto &g:ans) cout << g.a+1 << ' ' << g.b+1 << ' ' << g.c+1 << '\n';
    return 0;
}