#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    stack<pair<int,int>> st;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        st.push({a,a});
        while(st.size()>1){
            pair<int,int> t=st.top();
            st.pop();
            if(st.top().second>t.first){
                t={min(st.top().first,t.first),max(st.top().second,t.second)};
                st.pop();
                st.push(t);
            }
            else{
                st.push(t);
                break;
            }
        }
    }
    vector<pair<int,int>> ans;
    while(st.size()){
        ans.push_back(st.top());
        st.pop();
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    for(auto t:ans){
        cout << t.second-t.first+1 << ' ';
        for(int i=t.first;i<=t.second;i++) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}

// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// int vis[10];

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     srand(time(NULL));
//     int n;
//     cin >> n;
//     for(int i=0;i<n;i++){
//         int x=rand()%n+1;
//         while(vis[x]) x=rand()%n+1;
//         cout << x << ' ';
//         vis[x]=1;
//     }
//     return 0;
// }