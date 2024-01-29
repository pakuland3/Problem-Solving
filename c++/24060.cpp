#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string s;
int n;
ll ic;
int costs[1002];
int jcost=0;
int ans=0;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s >> ic;
        if(jcost==0){
            if(s=="jinju"){
                jcost=ic;
            }
            else{
                if(ic>1000) costs[1001]++;
                else costs[ic]++;
            }
        }
        else{
            if(ic>jcost) ans++;
        }
    }
    for(int i=jcost+1;i<=1001;i++){
        ans+=costs[i];
    }
    cout << jcost << '\n' << ans;
}