#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int aa[26],bb[26];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string a,b;
    cin >> a >> b;
    vector<string> ans;
    ans.push_back(a); ans.push_back(b);
    if(a.length()>b.length()) swap(ans[0],ans[1]);
    else if(a.length()==b.length()) sort(ans.begin(),ans.end());
    for(int i=0;i<a.length();i++) aa[a[i]-'a']++;
    for(int i=0;i<b.length();i++) bb[b[i]-'a']++;
    bool id=(a.length()==b.length()); if(id) for(int i=0;i<a.length();i++) if(a[i]!=b[i]) id=0;
    if(id){
        cout << ans[0] << " is identical to " << ans[1];
        return 0;
    }
    int dif=0;
    int cnt=0;
    for(int i=0;i<26;i++){
        dif+=abs(aa[i]-bb[i]);
        cnt+=(aa[i]!=bb[i]);
    }
    if(dif==0){
        cout << ans[0] << " is an anagram of " << ans[1];
        return 0;
    }
    if(a.length()==b.length()){
        if(cnt==2 && dif==2){
            cout << ans[0] << " is almost an anagram of " << ans[1];
            return 0;
        }
    }
    if(abs((int)a.length()-(int)b.length())==1){
        if(dif==1){
            cout << ans[0] << " is almost an anagram of " << ans[1];
            return 0;
        }
    }
    cout << ans[0] << " is nothing like " << ans[1];
    return 0;
}