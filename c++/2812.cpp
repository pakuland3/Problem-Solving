// TLE CODE O(n^2)
// #include <bits/stdc++.h>
// using namespace std;

// int n,k;
// char c;
// string ans("");
// int cnt=0,s=0;

// struct compare{
//     bool operator()(pair<int, int> &l, pair<int, int> &r){
//         if(l.first==r.first) return l.second>r.second;
//         return l.first<r.first;
//     }
// };

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
//     cin >> n >> k;
//     for(int i=0;i<n;i++){
//         cin >> c;
//         pq.push({c-'0',i});
//     }
//     while(cnt<n-k){
//         pair<int, int> now=pq.top();
//         pq.pop();
//         if(now.second<s) continue;
//         if(n-now.second-1>=n-k-cnt-1){
//             ans+=now.first+'0';
//             cnt++;
//             s=now.second;
//         }
//         else{
//             stack<pair<int, int>> st; st.push(now);
//             while(true){
//                 now=pq.top(); pq.pop(); st.push(now);
//                 if(n-now.second-1>=n-k-cnt-1){
//                     ans+=now.first+'0';
//                     cnt++;
//                     s=now.second;
//                     while(!st.empty()){
//                         if(st.top().second>s) pq.push(st.top());
//                         st.pop();
//                     }
//                     break;
//                 }
//             }
            
//         }
//     }
//     cout << ans;
//     return 0;
// }

//TLE SOLVE CODE -> O(2n)
//distinguish implementation and greedy algorithm
#include <bits/stdc++.h>
using namespace std;

string ans("");
int n,k,cnt=0;
char c;
deque<int> dq;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> c;
        while(!dq.empty() && c-'0'>dq.back() && cnt<k){
            dq.pop_back(); cnt++;
        }
        dq.push_back(c-'0');      
    }
    while(cnt<k){dq.pop_back();cnt++;}
    while(!dq.empty()){cout << dq.front();dq.pop_front();}
    cout << '\n';
    return 0;
}