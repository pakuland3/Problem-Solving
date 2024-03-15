#include <bits/stdc++.h>
using namespace std;

int n,a,b;
bool vis[100001]={0,};
int p[100001];
vector<int> tree[100001];

void dfs(){
    stack<int> st;
    st.push(1);
    while(!st.empty()){
        int now=st.top();
        vis[now]=1;
        st.pop();
        for(int i=0;i<tree[now].size();i++){
            if(!vis[tree[now][i]]){
                st.push(tree[now][i]);
                p[tree[now][i]]=now;
            }
        }
    }
    for(int i=2;i<=n;i++) cout << p[i] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs();
    return 0;
}