#include <bits/stdc++.h>
using namespace std;

int n;
int arr[501];
int d[501];
vector<int> graph[501];
vector<int> req[501];
int reqcnt[501];
queue<int> q;

void solve(){
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<req[now].size();i++) d[now]=max(d[now],d[req[now][i]]+arr[now]);
        for(int i=0;i<graph[now].size();i++){
            reqcnt[graph[now][i]]--;
            if(reqcnt[graph[now][i]]==0) q.push(graph[now][i]);
        }
    }
    for(int i=1;i<=n;i++) cout << d[i] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    memset(reqcnt,0,sizeof(reqcnt));
    int a=1;
    bool f=true;
    while(a<=n){
        int b;
        cin >> b; if(b==-1){a++;f=true;continue;}
        if(f){arr[a]=b;f=false;}
        else{graph[b].push_back(a);req[a].push_back(b);reqcnt[a]++;}
    }
    for(int i=1;i<=n;i++) if(reqcnt[i]==0){q.push(i);d[i]=arr[i];}
    solve();
}