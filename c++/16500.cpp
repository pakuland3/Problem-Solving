#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("0126.out","r",stdin);
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<vector<int>> graph(100,vector<int>());
    while(n--){
        string a;
        cin >> a;
        for(int i=0;i<s.length();i++){
            if(s[i]==a[0]){
                int b=1;
                for(int j=1;j<a.length();j++) if(a[j]!=s[i+j]) b=0;
                if(b) graph[i].push_back(i+a.length());
            }
        }
    }
    queue<int> q;
    int vis[101];
    memset(vis,0,sizeof(vis));
    q.push(0);
    int res=0;
    while(q.size()){
        int now=q.front();
        q.pop();
        if(now==s.length()){
            cout << 1;
            return 0;
        }
        for(int i=0;i<graph[now].size();i++){
            int nx=graph[now][i];
            if(vis[nx]) continue;
            vis[nx]=1;
            q.push(nx);
        }
    }
    cout << 0;
    return 0;
}

// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     freopen("0126.out","w",stdout);
//     for(int i=0;i<100;i++) cout << 'a';
//     cout << "\n100\n";
//     for(int i=0;i<100;i++) cout << "a\n";
//     return 0;
// }