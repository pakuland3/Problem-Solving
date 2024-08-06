#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool graph[10][10],vis[10][10];
int idgraph[10][10];
int id=0;
int n,m;
int parent[6];

struct edge{
    int a,b,c;
};

struct pos{
    int x,y;
};

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void bfs(int x, int y){
    queue<pos> q;
    q.push({x,y});
    vis[x][y]=1;
    idgraph[x][y]=id;
    while(!q.empty()){
        pos now=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=now.x+dx[i];
            int ny=now.y+dy[i];
            if(n<=nx || nx<0 || m<=ny || ny<0) continue;
            if(vis[nx][ny]) continue;
            if(!graph[nx][ny]) continue;
            vis[nx][ny]=1;
            q.push({nx,ny});
            idgraph[nx][ny]=id;
        }
    }
    id++;
}

int getParent(int a){
    if(a==parent[a]) return a;
    return parent[a]=getParent(parent[a]);
}

void unionParent(int a, int b){
    a=getParent(a);
    b=getParent(b);
    if(a>b) parent[a]=b;
    else parent[b]=a;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    vector<edge> e;
    for(int i=0;i<6;i++) parent[i]=i;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        cin >> graph[i][j];
        idgraph[i][j]=-1;
    }
    for(int i=0;i<n;i++){
        bool a=0;
        int b=0;
        int iid;
        for(int j=0;j<m;j++){
            if(j>0 && graph[i][j-1] && vis[i][j]) continue;
            if(graph[i][j] && !vis[i][j]) bfs(i,j);
            if(!a && graph[i][j]){
                iid=idgraph[i][j];
            }
            if(graph[i][j]) a=1;
            if(a && !graph[i][j] && graph[i][j-1]){
                iid=idgraph[i][j-1];
                b=j-1;
            }
            if(a && graph[i][j] && iid!=idgraph[i][j]){
                if(j-b>2) e.push_back({iid,idgraph[i][j],j-b-1});
            }
        }
    }
    for(int i=0;i<m;i++){
        bool a=0;
        int b=0;
        int iid;
        for(int j=0;j<n;j++){
            if(j>0 && graph[j-1][i] && vis[j][i]) continue;
            if(graph[j][i] && !vis[j][i]) bfs(j,i);
            if(!a && graph[j][i]){
                iid=idgraph[j][i];
            }
            if(graph[j][i]) a=1;
            if(a && !graph[j][i] && graph[j-1][i]){
                iid=idgraph[j-1][i];
                b=j-1;
            }
            if(a && graph[j][i] && iid!=idgraph[j][i]){
                if(j-b>2) e.push_back({iid,idgraph[j][i],j-b-1});
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++) cout << idgraph[i][j] << ' ';
    //     cout << '\n';
    // }
    int ans=0;
    sort(e.begin(),e.end(),[](edge &l, edge &r) -> bool {return l.c<r.c;});
    for(int i=0;i<e.size();i++){
        edge cur=e[i];
        if(getParent(cur.a)==getParent(cur.b)) continue;
        ans+=cur.c;
        unionParent(cur.a,cur.b);
    }
    for(int i=0;i<id;i++) if(getParent(parent[i])!=0){
        cout << -1; return 0;
    }
    cout << ans;
    return 0;
}