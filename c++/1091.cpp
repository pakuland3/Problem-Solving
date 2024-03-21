#include <bits/stdc++.h>
using namespace std;

int n,tmp,ans=0;;
vector<int> ans_arr[3];
vector<int> carr[3];
deque<int> st_arr[48];
vector<int> rule_arr(48);

bool ck(){
    bool b=true;
    if(ans_arr[0].size()==n/3 && ans_arr[1].size()==n/3 && ans_arr[2].size()==n/3){
        for(int i=0;i<n/3;i++){
            if(ans_arr[0][i]%3!=0) b=false;
            if(ans_arr[1][i]%3!=1) b=false;
            if(ans_arr[2][i]%3!=2) b=false;
            if(!b) break;
        }
    }
    if(b) return true;
    if(ans_arr[0].size()!=carr[0].size()) return false;
    if(ans_arr[1].size()!=carr[1].size()) return false;
    if(ans_arr[2].size()!=carr[2].size()) return false;
    for(int i=0;i<ans_arr[0].size();i++) if(ans_arr[0][i]!=carr[0][i]) return false;
    for(int i=0;i<ans_arr[1].size();i++) if(ans_arr[1][i]!=carr[1][i]) return false;
    for(int i=0;i<ans_arr[2].size();i++) if(ans_arr[2][i]!=carr[2][i]) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++) st_arr[i].push_back(i);
    for(int i=0;i<n;i++){
        cin >> tmp;
        ans_arr[tmp].push_back(i);
    }
    for(int i=0;i<n;i++){
        cin >> tmp;
        carr[i%3].push_back(tmp);
        rule_arr[i]=tmp;
    }
    for(int i=0;i<3;i++) sort(carr[i].begin(),carr[i].end());
    if(!ck()){cout << -1; return 0;}
    while(st_arr[0][0]!=ans_arr[0][0]){
        for(int i=0;i<n;i++){
            st_arr[rule_arr[i]].push_back(st_arr[i].front());
            st_arr[i].pop_front();
        }
        ans++;
    }
    cout << ans;
    return 0;
}