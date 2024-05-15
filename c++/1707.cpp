#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int k;
    cin >> k;
    while(k--){
        int v,e;
        cin >> v >> e;
        vector<vector<int>> graph(v+1, vector<int> ());
        vector<int> mark(v+1,-1);
        vector<bool> vis(v+1,0);
        for(int i=0;i<e;i++){
            int a,b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        bool ans=1;
        for(int i=1;i<=v;i++){
            if(!ans) break;
            if(vis[i]) continue;
            stack<int> st;
            st.push(i);
            vis[i]=1;
            mark[i]=0;
            while(!st.empty()){
                int now=st.top();
                st.pop();
                for(int j=0;j<graph[now].size();j++){
                    if(mark[graph[now][j]]==mark[now]) ans=0;
                    if(!vis[graph[now][j]]){
                        st.push(graph[now][j]);
                        vis[graph[now][j]]=1;
                        mark[graph[now][j]]=!mark[now];
                    }
                }
            }
        }
        cout << ((ans)?"YES\n":"NO\n");
    }
    return 0;
}