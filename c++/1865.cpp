#include <bits/stdc++.h>
#define INF (int)(25e6+7)
typedef long long ll;
using namespace std;

struct eg{
    int s,e,c;
};

bool bellman_ford(int n, vector<int> &d, vector<eg> &graph){
    for(int i=0;i<n;i++){
        for(int j=0;j<graph.size();j++){
            int cur=graph[j].s;
            int next=graph[j].e;
            int cost=graph[j].c;
            if(d[next]>d[cur]+cost){
                if(i==n-1) return 1;
                d[next]=d[cur]+cost;
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,m,w;
        cin >> n >> m >> w;
        vector<int> d(n,INF);
        vector<eg> graph;
        while(m--){
            int s,e,t;
            cin >> s >> e >> t;
            graph.push_back({--s,--e,t});
            graph.push_back({e,s,t});
        }
        while(w--){
            int s,e,t;
            cin >> s >> e >> t;
            t*=-1;
            graph.push_back({--s,--e,t});
        }
        if(bellman_ford(n,d,graph)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}