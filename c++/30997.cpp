#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int gcd(ll a, ll b){
    ll c;
    while(b){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int n,m,k;
int arr[101];
int ini;
pair<int, int> ans_pair;
double ansp=0;
tuple<int, int, int> ans_tuple;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i=0;i<3*(m-1);i++){
        cin >> ini;
        arr[ini]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int l=j+1;l<=n;l++){
                arr[i]++;arr[j]++;arr[l]++; 
                int soni=arr[i]+arr[j]+arr[l];
                int moti=3*m;
                ll sonl=1;
                ll motl=moti;
                for(int cnt=0;cnt<k;cnt++){
                    sonl*=(moti-soni);
                    motl*=moti;
                }
                sonl*=soni;
                double goalp=(double)sonl/motl;
                if(goalp>ansp){
                    int gcdi=gcd(sonl,motl);
                    ans_pair.first=sonl/gcdi;
                    ans_pair.second=motl/gcdi;
                    ans_tuple={i,j,l};
                    ansp=goalp;
                }
                arr[i]--;arr[j]--;arr[l]--;
            }
        }
    }
    cout << ans_pair.first << ' ' << ans_pair.second << '\n';
    cout << get<0>(ans_tuple) << ' ' << get<1>(ans_tuple) << ' ' << get<2>(ans_tuple);
}