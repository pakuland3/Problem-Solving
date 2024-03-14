#include <bits/stdc++.h>
using namespace std;

int n,m,inn;
priority_queue<int, vector<int>, greater<int>> ppq;
priority_queue<int, vector<int>, greater<int>> npq;

int solve(priority_queue<int, vector<int>, greater<int>> ppq, priority_queue<int, vector<int>, greater<int>> npq){
    int cnt,ans=0;
    if(ppq.size()%m!=0){
        cnt=ppq.size()%m;
        for(int i=1;i<cnt;i++) ppq.pop();
        if(ppq.size()==1 && npq.empty()) ans+=ppq.top();
        else ans+=2*ppq.top();
        ppq.pop();
    }
    while(!ppq.empty()){
        for(int i=1;i<m;i++) ppq.pop();
        if(ppq.size()==1 && npq.empty()) ans+=ppq.top();
        else ans+=2*ppq.top();
        ppq.pop();
    }
    if(npq.size()%m!=0){
        cnt=npq.size()%m;
        for(int i=1;i<cnt;i++) npq.pop();
        if(npq.size()==1) ans+=npq.top();
        else ans+=2*npq.top();
        npq.pop();
    }
    while(!npq.empty()){
        for(int i=1;i<m;i++) npq.pop();
        if(npq.size()==1) ans+=npq.top();
        else ans+=2*npq.top();
        npq.pop();
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> inn;
        if(inn>0) ppq.push(inn);
        else npq.push(-inn);
    }
    cout << min(solve(ppq,npq),solve(npq,ppq));
    return 0;
}