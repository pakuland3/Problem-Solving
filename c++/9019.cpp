#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int dp[10000];
char p[10000];

void re(int n, int *k){
    k[0]=n/1000;
    k[1]=(n%1000)/100;
    k[2]=(n%100)/10;
    k[3]=n%10;
}

int getNumber(int* k){ return k[0]*1000+k[1]*100+k[2]*10+k[3]; }

void D(int* k){
    int a=getNumber(k);
    a*=2;
    a%=10000;
    re(a,k);
}

void S(int* k){
    int a=getNumber(k);
    if(a==0) a=9999;
    else a--;
    re(a,k);
}

void L(int* k){
    int tmp=k[0];
    k[0]=k[1];
    k[1]=k[2];
    k[2]=k[3];
    k[3]=tmp;
}

void R(int* k){
    int tmp=k[3];
    k[3]=k[2];
    k[2]=k[1];
    k[1]=k[0];
    k[0]=tmp;
}

pair<bool, int> solve(int now, int* k, char sign){
    bool update=0;
    int t;
    re(now,k);
    if(sign=='D') D(k);
    if(sign=='S') S(k);
    if(sign=='L') L(k);
    if(sign=='R') R(k);
    t=getNumber(k);
    if(dp[t]==-1){
        update=1;
        p[t]=sign;
        dp[t]=now;
    }
    return {update,t};
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        int a,b;
        cin >> a >> b;
        fill(dp,dp+10000,-1);
        int k[4];
        dp[a]=a;
        queue<int> q;
        q.push(a);
        while(!q.empty()){
            int now=q.front();
            if(now==b) break;
            q.pop();
            pair<bool,int> pp=solve(now,k,'D');
            if(pp.first) q.push(pp.second);
            pp=solve(now,k,'S');
            if(pp.first) q.push(pp.second);
            pp=solve(now,k,'L');
            if(pp.first) q.push(pp.second);
            pp=solve(now,k,'R');
            if(pp.first) q.push(pp.second);
        }
        stack<char> st;
        while(b!=dp[b]){
            st.push(p[b]);
            b=dp[b];
        }
        while(!st.empty()){
            cout << st.top();
            st.pop();
        }
        cout << '\n';
    }
    return 0;
}