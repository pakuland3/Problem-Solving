#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int v,e,islands=0;
        cin >> v >> e;
        vector<int> mark(v,-1);
        vector<vector<int>> graph(v, vector<int> ());
        vector<bool> vis(v,0);
        bool ans=1;
        for(int i=0;i<e;i++){
            int a,b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i=0;i<v;i++){
            if(!ans) break;
            if(vis[i]) continue;
            stack<int> st;
            vis[i]=1;
            if(graph[i].size()==0){islands++; continue;}
            mark[i]=0;
            st.push(i);
            while(!st.empty() && ans){
                int now=st.top();
                st.pop();
                for(int j=0;j<graph[now].size();j++){
                    if(mark[now]==mark[graph[now][j]]){ans=0; break;}
                    mark[graph[now][j]]=!mark[now];
                    if(vis[graph[now][j]]) continue;
                    vis[graph[now][j]]=1;
                    st.push(graph[now][j]);
                }
            }
        }
        if(!ans){cout << "-1\n"; continue;}
        ll outP=pow(2,islands+1);
        if(v>islands) cout << (islands>0?outP:2) << '\n';
        else cout << outP/2 << '\n';
    }
    return 0;
}