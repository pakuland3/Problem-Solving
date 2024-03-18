#include <bits/stdc++.h>
typedef long long ll;
#define MAX 2e6
using namespace std;

bool pnum[(int)MAX+1]={0,};
vector<int> primes;
int t;

void eratosthenes(){
    for(int i=2;i<=(int)MAX;i++){
        if(pnum[i]) continue;
        primes.push_back(i);
        for(int j=i*2;j<=MAX;j+=i) pnum[j]=true;        
    }
}

void solve(){
    ll A,B,S;
    cin >> A >> B; S=A+B;
    if(S<=3) cout << "NO";
    else if(S%2==0) cout << "YES";
    else{
        S-=2;
        bool b=true;
        if(S>MAX){
            for(int i=0;i<primes.size();i++){
                if(S%primes[i]==0) b=false;
            }
        }
        else if(pnum[S]) b=false;

        if(b) cout << "YES";
        else cout << "NO";
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    eratosthenes();
    cin >> t;
    while(t--) solve();
    return 0;
}