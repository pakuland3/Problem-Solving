#include <bits/stdc++.h>
using namespace std;

int n,tmp;
vector<int> arr;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> tmp; arr.push_back(tmp);
    for(int i=1;i<n;i++){
        cin >> tmp;
        if(arr.back()<tmp) arr.push_back(tmp);
        else{
            auto it=lower_bound(arr.begin(),arr.end(),tmp);
            *it=tmp;
        }
    }
    cout << arr.size();
    return 0;
}