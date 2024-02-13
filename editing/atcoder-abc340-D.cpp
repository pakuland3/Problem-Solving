#include <bits/stdc++.h>
#define INF 1e15
typedef long long ll;
using namespace std;

int n;
vector<pair<int, int>> graph[200001];
int a,b,x;
ll d[200001];

void dijkstra(){
    priority_queue<pair<ll, int>,vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> a >> b >> x;
        graph[i].push_back({i+1,a});
        graph[i].push_back({x,b});
    }

}