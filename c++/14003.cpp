#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; vector<int> inn(n),arr; cin >> inn[0];
    arr.push_back(inn[0]); vector<int> ind(n); ind[0]=0;
    for(int i=1;i<n;i++){
        cin >> inn[i];
        if(arr.back()<inn[i]){arr.push_back(inn[i]);ind[i]=arr.size()-1;}
        else{
            auto it=lower_bound(arr.begin(),arr.end(),inn[i]);
            *it=inn[i];
            ind[i]=it-arr.begin();
        }
    }
    int ans_ind=arr.size()-1; int cnt=0;
    for(int i=0;i<n;i++){
        if(ans_ind-cnt==ind[n-i-1]){
            arr[ans_ind-cnt]=inn[n-i-1];
            cnt++;
            if(cnt==ans_ind+1) break;
        }
    }
    cout << arr.size() << '\n';
    for(int i=0;i<=ans_ind;i++) cout << arr[i] << ' ';
    return 0;
}