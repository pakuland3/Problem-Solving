#include <bits/stdc++.h>
using namespace std;

int n,k;
char s[500000];
string ans("");
int s=0,cnt=0;

struct compare{
    bool operator()(pair<int, int> &l, pair<int, int> &r){
        return l.first>r.first;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> s[i];
        pq.push({s[i]-'0',i});
    }
    while(cnt<n-k){
        pair<int, int> now=pq.top();
        pq.pop();
        if(n-(now.second+1)>=n-k-cnt)
    }
    return 0;
}