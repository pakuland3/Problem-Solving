//UNION FIND PROBLEM

// #include <bits/stdc++.h>
// using namespace std;

// int m,n,k,c;
// vector<vector<int>> arr;
// bool ck[100]={0,},ans=0;

// void solve(int cnt,int ind){
//     if(ans) return;
//     if(cnt==k){
//         bool t=1;
//         for(int i=0;i<n;i++) if(!ck[i]) t=0;
//         if(t) ans=1;
//         return;
//     }
//     bool b=0;
//     for(int i=ind+1;i<n;i++){
//         ck[i]=1;
//         solve(cnt+1,i);
//         ck[i]=0;
//         if(!b) b=1;
//     }
//     if(!b){
//         bool t=1;
//         for(int i=0;i<n;i++) if(!ck[i]) t=0;
//         if(t) ans=1;
//         return;
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     cin >> m >> n >> k;
//     for(int i=0;i<m;i++){
//         arr.push_back(vector<int> ());
//         for(int j=0;j<n;j++){
//             cin >> c; if(c==0) arr.back().push_back(j);
//         }
//         if(arr.back().size()==0) arr.pop_back();
//     }
//     for(int i=0;i<arr.size();i++){ck[i]=1;solve(1,i);ck[i]=0;}
//     if(ans) cout << "yes";
//     else cout << "no";
// }