#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001];
bool vis[1000];
int n,m;
int arr[2];
int ans=0;

bool bfs(int s){
    if(vis[s]) return false;
    vis[s]=true;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto elem:graph[x]){
            if(!vis[elem]){
                q.push(elem);
                vis[elem]=true;
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> arr[0] >> arr[1];
        graph[arr[0]].push_back(arr[1]);
        graph[arr[1]].push_back(arr[0]);
    }
    for(int i=1;i<=n;i++){
        if(bfs(i)) ans++;
    }
    cout << ans;
}