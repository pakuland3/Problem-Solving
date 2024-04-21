#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,tmp,ans=0;
    cin >> n;
    deque<int> dq[48];
    vector<int> p(n),s(n),ind(n);
    for(int i=0;i<n;i++) cin >> p[i];
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=0;i<n;i++){dq[i].push_back(i);ind[i]=i;}
    for(int i=0;i<200000;i++){
        bool b=1;
        for(int i=0;i<n;i++){
            if(ind[i]%3!=p[i]){b=0;break;}
        }
        if(b){
            cout << ans;
            return 0;
        }
        for(int i=0;i<n;i++){
            dq[s[i]].push_back(dq[i].front());
            ind[dq[i].front()]=s[i];
            dq[i].pop_front();
        }
        ans++;
    }
    cout << -1;
    return 0;
}