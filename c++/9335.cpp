// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
//         vector<vector<int>> graph(n);
//         bool vis[20]={0,};
//         int ans=0;
//         for(vector<int> &a:graph){
//             int c;
//             cin >> c;
//             for(int i=0;i<c;i++){
//                 int m;
//                 cin >> m;
//                 a.push_back(--m);
//             }
//         }
//         for(int i=0;i<n;i++){
//             for(int j=0;j<graph[i].size();j++){
//                 bool flag=0;
//                 for(int k=0;k<graph[graph[i][j]].size();k++) if(graph[graph[i][j]][k]==i) flag=1;
//                 if(!flag) graph[graph[i][j]].push_back(i);
//             }
//         }
//         for(int i=0;i<n;i++) pq.push({graph[i].size(),i});
//         while(!pq.empty()){
//             pair<int,int> a=pq.top();
//             pq.pop();
//             bool flag=!vis[a.second];
//             vis[a.second]=1;
//             for(int i=0;i<graph[a.second].size();i++){
//                 if(!vis[graph[a.second][i]]) flag=1;
//                 vis[graph[a.second][i]]=1;
//             }
//             if(flag) ans++;
//         }
//         cout << ans << '\n';
//     }
//     return 0;
// }

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans=21;
        vector<vector<int>> graph(n);
        for(vector<int> &a:graph){
            int c;
            cin >> c;
            for(int i=0;i<c;i++){
                int b;
                cin >> b;
                a.push_back(--b);
            }
        }
        int c=1<<n;
        for(int i=1;i<c;i++){
            int d=0;
            bool vis[20]={0,};
            int k=i;
            int idx=0;
            int cnt=0;
            while(k){
                if(k&1){
                    cnt++;
                    d+=!vis[idx];
                    vis[idx]=1;
                    for(int j=0;j<graph[idx].size();j++){
                        d+=!vis[graph[idx][j]];
                        vis[graph[idx][j]]=1;
                    }
                }
                idx++;
                k>>=1;
            }
            if(d==n) ans=min(ans,cnt);
        }
        cout << ans << '\n';
    }
    return 0;
}