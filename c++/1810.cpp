// #include <bits/stdc++.h>
// #define pii pair<int,int>
// #define fi first
// #define se second
// #define INF INT32_MAX
// typedef long long ll;
// using namespace std;

// int n,f;
// vector<vector<pair<int,vector<int>>>> graph;
// map<pii,int> m;
// vector<pii> a;
// int dx[]={-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,1,2,-2,-1,0,1,2,-2,-1,0,1,2};
// int dy[]={2,2,2,2,2,1,1,1,1,1,0,0,0,0,-1,-1,-1,-1,-1,-2,-2,-2,-2,-2};
// vector<int> dis[]={{0,2,0},{0,0,1},{2,0,0},{0,0,1},{0,2,0},{0,0,1},{0,1,0},{1,0,0},{0,1,0},{0,0,1},{2,0,0},{1,0,0},{1,0,0},{2,0,0},{0,0,1},{0,1,0},{1,0,0},{0,1,0},{0,0,1},{0,2,0},{0,0,1},{2,0,0},{0,0,1},{0,2,0}};
// vector<vector<int>> d;
// priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;

// double gd(vector<int> &d){
//     return d[0]+d[1]*sqrt(2)+d[2]*sqrt(3);
// }

// void dijkstra(){
//     d[0]={0,0,0};
//     pq.push({0,0});
//     while(!pq.empty()){
//         int now=pq.top().se;
//         double cdis=pq.top().fi;
//         pq.pop();
//         for(int i=0;i<graph[now].size();i++){
//             int nx=graph[now][i].fi;
//             double cost=cdis+gd(graph[now][i].se);
//             if(cost<gd(d[nx])){
//                 d[nx]={d[now][0]+graph[now][i].se[0],d[now][1]+graph[now][i].se[1],d[now][2]+graph[now][i].se[2]};
//                 pq.push({cost,nx});
//             }
//         }
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     cin >> n >> f;
//     graph.resize(n+1);
//     a.resize(n+1);
//     d.resize(n+1,{50001,50001,50001});
//     m.insert({{0,0},0});
//     a[0]={0,0};
//     for(int i=1;i<=n;i++){
//         cin >> a[i].fi >> a[i].se;
//         if(m.find(a[i])==m.end()) m.insert({a[i],i});
//     }
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<24;j++){
//             auto it=m.find({a[i].fi+dx[j],a[i].se+dy[j]});
//             if(it!=m.end()) graph[i].push_back({it->second,dis[j]});
//         }
//     }
//     dijkstra();
//     double ans=INF;
//     for(int i=1;i<=n;i++) if(a[i].se>=f) ans=min(ans,gd(d[i]));
//     cout << (ans!=INF?round(ans):-1);
//     return 0;
// }

// #include <bits/stdc++.h>
// #define pii pair<int,int>
// #define fi first
// #define se second
// #define INF INT32_MAX
// typedef long long ll;
// using namespace std;

// int n,f;
// vector<vector<pair<int,int>>> graph;
// map<pii,int> m;
// vector<pii> a;
// int dx[]={-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,1,2,-2,-1,0,1,2,-2,-1,0,1,2};
// int dy[]={2,2,2,2,2,1,1,1,1,1,0,0,0,0,-1,-1,-1,-1,-1,-2,-2,-2,-2,-2};
// int dis[]={20,1,200,1,20,1,10,100,10,1,200,100,100,200,1,10,100,10,1,20,1,200,1,20};
// vector<vector<int>> d;
// vector<int> tmp(3);
// priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;

// double getDouble(vector<int> &a){
//     return a[0]+a[1]*sqrt(2)+a[2]*sqrt(5);
// }

// double getDouble(int a){
//     double s=sqrt(5)*(a%10);
//     a/=10;
//     s+=sqrt(2)*(a%10);
//     a/=10;
//     return a+s;
// }

// void dijkstra(){
//     d[0][0]=0;
//     d[0][1]=0;
//     d[0][2]=0;
//     pq.push({0,0});
//     while(!pq.empty()){
//         int now=pq.top().se;
//         pq.pop();
//         for(int i=0;i<graph[now].size();i++){
//             int nx=graph[now][i].fi;
//             int t=graph[now][i].se;
//             for(int j=2;j>=0;j--){
//                 tmp[j]=d[now][j]+t%10;
//                 t/=10;
//             }
//             if(getDouble(tmp)<getDouble(d[nx])){
//                 for(int j=0;j<3;j++) d[nx][j]=tmp[j];
//                 pq.push({getDouble(d[nx]),nx});
//             }
//         }
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     cin >> n >> f;
//     graph.resize(n+1);
//     a.resize(n+1);
//     d.resize(n+1,vector<int>(3,16667));
//     m.insert({{0,0},0});
//     a[0]={0,0};
//     for(int i=1;i<=n;i++){
//         cin >> a[i].fi >> a[i].se;
//         if(m.find(a[i])==m.end()) m.insert({a[i],i});
//     }
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<24;j++){
//             auto it=m.find({a[i].fi+dx[j],a[i].se+dy[j]});
//             if(it!=m.end()) graph[i].push_back({it->second,dis[j]});
//         }
//     }
//     dijkstra();
//     double ans=INF;
//     for(int i=0;i<=n;i++) if(a[i].se>=f) ans=min(ans,getDouble(d[i]));
//     cout << (ans!=INF?round(ans):-1);
//     return 0;
// }

#include <bits/stdc++.h>
#define sq2 sqrt(2)
#define sq5 sqrt(5)
#define pii pair<int,int>
#define fi first
#define se second
#define INF INT32_MAX
typedef long long ll;
using namespace std;

int n,f;
vector<vector<pair<int,double>>> graph;
map<pii,int> m;
vector<pii> a;
int dx[]={-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,1,2,-2,-1,0,1,2,-2,-1,0,1,2};
int dy[]={2,2,2,2,2,1,1,1,1,1,0,0,0,0,-1,-1,-1,-1,-1,-2,-2,-2,-2,-2};
double dis[]={2*sq2,sq5,2,sq5,2*sq2,sq5,sq2,1,sq2,sq5,2,1,1,2,sq5,sq2,1,sq2,sq5,2*sq2,sq5,2,sq5,2*sq2};
vector<double> d;

void dijkstra(){
    d[0]=0;
    priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        int now=pq.top().se;
        double cdis=pq.top().fi;
        pq.pop();
        for(int i=0;i<graph[now].size();i++){
            int nx=graph[now][i].fi;
            double cost=cdis+graph[now][i].se;
            if(cost<d[nx]){
                d[nx]=cost;
                pq.push({cost,nx});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> f;
    graph.resize(n+1);
    a.resize(n+1);
    d.resize(n+1,INF);
    m.insert({{0,0},0});
    a[0]={0,0};
    for(int i=1;i<=n;i++){
        cin >> a[i].fi >> a[i].se;
        if(m.find(a[i])==m.end()) m.insert({a[i],i});
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<24;j++){
            auto it=m.find({a[i].fi+dx[j],a[i].se+dy[j]});
            if(it!=m.end()) graph[i].push_back({it->second,dis[j]});
        }
    }
    dijkstra();
    double ans=INF;
    for(int i=0;i<=n;i++) if(a[i].se>=f) ans=min(ans,d[i]);
    cout << (ans!=INF?round(ans):-1);
    return 0;
}