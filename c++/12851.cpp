#include <bits/stdc++.h>
using namespace std;

int dp[100001][2];
int n,k;
int dx[]={1,-1};

void bfs(){
    queue<int> q;
    q.push(n);
    dp[n][0]=0; dp[n][1]=1;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<2;i++){
            int next=now+dx[i];
            if(-1<next && next<100001){
                if(dp[next][0]>dp[now][0]+1){
                    dp[next][0]=dp[now][0]+1;
                    dp[next][1]=dp[now][1]; 
                    q.push(next);
                } //definitely not searching exist
                else if(dp[next][0]==dp[now][0]+1) dp[next][1]+=dp[now][1];
            }
        }
        int next=now*2;
        if(next<100001){
            if(dp[next][0]>dp[now][0]+1){
                dp[next][0]=dp[now][0]+1;
                dp[next][1]=dp[now][1];
                q.push(next);
            }
            else if(dp[next][0]==dp[now][0]+1) dp[next][1]+=dp[now][1];
        }
    }
    cout << dp[k][0] << '\n' << dp[k][1];
}

int main(){
    cin >> n >> k;
    for(int i=0;i<100001;i++){dp[i][0]=10000000;}
    if(k<=n) cout << n-k << 1;
    else bfs();
}