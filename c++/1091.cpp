#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    deque<int> setup[n];
    vector<int> rule3[3],rule(n),dest[3];
    for(int i=0;i<n;i++) setup[i].push_back(i);
    for(int i=0;i<n;i++){
        int inn; cin >> inn; setup[i]=inn;
        dest[inn].push_back(i);
    }
    for(int i=0;i<n;i++){
        cin >> rule[i];
        rule3[i%3].push_back(rule[i]);
    }
    for(int i=0;i<3;i++) sort(rule3[i].begin(),rule3[i].end());
    if(dest[0].size()==dest[1].size() && dest[1].size()==dest[2].size()){
        bool b=true;
        for(int i=0;i<n/3;i++){
            if(dest[0][i]!=0) b=false;
            if(dest[1][i]!=1) b=false;
            if(dest[2][i]!=2) b=false;
            if(!b) break;
        }
        if(b){cout << 0; return 0;}
    }
    for(int i=0;i<rule3[0].size();i++){
        if(rule3[0].size()!=dest[0].size()){cout << -1; return 0;}
        if(rule3[0][i]!=dest[0][i]){cout << -1; return 0;}
    }
    for(int i=0;i<rule3[1].size();i++){
        if(rule3[1].size()!=dest[1].size()){cout << -1; return 0;}
        if(rule3[1][i]!=dest[1][i]){cout << -1; return 0;}
    }
    for(int i=0;i<rule3[2].size();i++){
        if(rule3[2].size()!=dest[2].size()){cout << -1; return 0;}
        if(rule3[2][i]!=dest[2][i]){cout << -1; return 0;}
    }
    int cnt=0;
    while(true){
        bool b=true;
        for(int i=0;i<n;i++){
            setup[rule[i]].push_back(setup[i].front());
            setup[i].pop_front();
        }
        cnt++;
        for(int i=0;i<3;i++){
            for(int j=0;j<n/3;j++){
                if(!binary_search(dest[i].begin(),dest[i].end(),setup[j*3+i].front())) b=false;
            }
        }
        if(b) break;
    }
    cout << cnt;
    return 0;
}