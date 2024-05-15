// backtracking could not solve

// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// int m,n,k,tmp;
// bool b=0;
// vector<vector<int>> arr;
// vector<int> parent;

// void unionParent(int a,int b){
//     parent[b]=a;
// }

// void solve(int backnode,int ind,int st,int cnt){
//     if(b) return;
//     if(cnt==n){cout << "yes"; b=1; return;}
//     if(st==k) return;
//     for(int i=ind+1;i<m;i++){
//         if(arr[i].size()==0) continue;
//         if(backnode!=-1){
//             vector<int> tmp; for(int j=0;j<arr[i].size();j++){
//                 if(parent[arr[i][j]]!=backnode) tmp.push_back(arr[i][j]);
//             }
//             for(int to:tmp) unionParent(backnode,to);
//             solve(backnode,i,st+1,cnt+tmp.size());
//             for(int j=0;j<tmp.size();j++) parent[tmp[j]]=tmp[j];
//         }
//         else{
//             backnode=arr[i][0];
//             for(int j=1;j<arr[i].size();j++) unionParent(backnode,arr[i][j]);
//             solve(backnode,i,1,arr[i].size());
//             backnode=-1;
//             for(int j=0;j<n;j++) parent[j]=j;
//         }
//     }
//     return;
// }


// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     // freopen("input.txt","r",stdin);
//     cin >> m >> n >> k;
//     arr.resize(m,vector<int> ());
//     for(int i=0;i<m;i++) for(int j=0;j<n;j++){
//         cin >> tmp;
//         if(tmp==0) arr[i].push_back(j);
//     }
//     parent.resize(n);
//     for(int i=0;i<n;i++) parent[i]=i;
//     solve(-1,-1,0,0);
//     if(!b) cout << "no";
//     return 0;
// }

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int m,n,k;
    cin >> m >> n >> k;
    vector<int> parent(n+1,-1);
    
    return 0;
}