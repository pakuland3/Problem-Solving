#include <bits/stdc++.h>
using namespace std;

int n,k;
long long ans=0;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    vector<pair<int, int>> jw(n);
    vector<int> bp(k);
    priority_queue<int> pq;
    for(int i=0;i<n;i++) cin >> jw[i].first >> jw[i].second;
    for(int i=0;i<k;i++) cin >> bp[i];
    sort(bp.begin(), bp.end());
    sort(jw.begin(),jw.end(),[](pair<int, int> l, pair<int, int> r)->bool{return l.first<r.first;});
    int ind=0;
    for(int i=0;i<k;i++){
        while(ind<n){
            if(jw[ind].first<=bp[i]){
                pq.push(jw[ind].second);
                ind++;
            }
            else break;
        }
        if(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
    }
    cout << ans;
    return 0;
}

// 오늘 배운 prority_queue compare 사용방법
// pq의 3번째 인자에는 구조체가 들어가야함(greater<>나, less<>의 <> 속에 구현체가 들어가야하는 것(tmplate임))
// pair를 예시로 들자면 다음과 같다.
// struct compare{
//     bool operator()(pair<int, int> &l, pair<int, int> &r){
//         if(l.first==r.first) return l.second<r.second;
//         return l.first<r.first;
//     }
// };