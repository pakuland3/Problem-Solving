#include <bits/stdc++.h>
#define piii pair<int, pair<int, int>>
#define f first
#define s second
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int des;
    cin >> des;
    vector<vector<bool>> vis(10000,vector<bool> (10000,0));
    vis[1][0]=1;
    queue<piii> q;
    q.push({0,{1,0}});
    while(1){
        piii cp=q.front();
        q.pop();
        if(cp.s.f==des){cout << cp.f; return 0;}
        if(!vis[cp.s.f][cp.s.f]){q.push({cp.f+1,{cp.s.f,cp.s.f}}); vis[cp.s.f][cp.s.f]=1;}
        if(cp.s.f>0 && !vis[cp.s.f-1][cp.s.s]){q.push({cp.f+1,{cp.s.f-1,cp.s.s}}); vis[cp.s.f-1][cp.s.s]=1;}
        if(!vis[cp.s.f+cp.s.s][cp.s.s] && cp.s.s>0){q.push({cp.f+1,{cp.s.f+cp.s.s,cp.s.s}}); vis[cp.s.f+cp.s.s][cp.s.s]=1;}
    }
    return 0;
}