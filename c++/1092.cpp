#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//    freopen("input.txt","r",stdin);
    int n,m,tmp,ans=0;
    cin >> n;
    vector<int> cr(n);
    deque<int> dq;
    for(int &a:cr) cin >> a;
    sort(cr.begin(),cr.end(),greater<int>());
    cin >> m;
    while(m--){cin >> tmp; dq.push_back(tmp);}
    sort(dq.begin(),dq.end(),greater<int>());
    while(!dq.empty()){
        bool b=1,d=0;
        int cnt=0,cursize=dq.size();
        for(int i=0;i<n;i++){
            if(cursize==cnt) break;
            if(cr[i]>=dq.front()){
                dq.pop_front();
                cursize--;
                b=0;
            }
            else{
                int k=cursize-cnt;
                for(int j=0;j<k;j++){
                    if(cr[i]<dq.front()){
                        dq.push_back(dq.front());
                        dq.pop_front();
                        cnt++;
                    }
                    else{
                        dq.pop_front();
                        cursize--;
                        b=0;
                        break;
                    }
                }
            }
        }
        for(int i=0;i<cursize-cnt;i++){dq.push_back(dq.front()); dq.pop_front();}
        ans++;
        if(b){cout << -1; return 0;}
    }
    cout << ans;
    return 0;
}