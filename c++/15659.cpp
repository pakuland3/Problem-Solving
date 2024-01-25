#include <iostream>
#include <vector>
#include <string>
using namespace std;

int mini=(1 << 30);
int maxi=-mini;
int n;
int arr[11];
int signs[4];
vector<int> v; //0 -1 -2 -3
vector<string> strs;

void solve(int ind, int a, int b, int c, int d){
	if(ind==n-1){
		int cur=-1;
		for(int i=0;i<n-1;i++){
			if(v[i]==0){
				if(cur==-1){
					strs.push_back(to_string(arr[i]));
					strs.push_back("plus");
				}
				else{
					strs.push_back(to_string(cur));
					strs.push_back("plus");
					cur=-1;
				}
			}
			else if(v[i]==-1){
				if(cur==-1){
					strs.push_back(to_string(arr[i]));
					strs.push_back("minus");
				}
				else{
					strs.push_back(to_string(cur));
					strs.push_back("minus");
					cur=-1;
				}
			}
			else if(v[i]==-2){
				if(cur==-1){
					cur=arr[i]*arr[i+1];
				}
				else{
					cur*=arr[i+1];
				}
			}
			else if(v[i]==-3){
				if(cur==-1){
					cur=arr[i]/arr[i+1];
				}
				else{
					cur/=arr[i+1];
				}
			}
			if(i==n-2){
				if(strs.empty() || strs[strs.size()-1]=="plus" || strs[strs.size()-1]=="minus"){
					if(cur!=-1) strs.push_back(to_string(cur));
					else strs.push_back(to_string(arr[i+1]));
				}
			}
		}
		int sum=stoi(strs[0]);
		for(int i=1;i<strs.size();i++){
			if(strs[i]=="plus"){
				sum+=stoi(strs[i+1]);
				i++;
			}
			else if(strs[i]=="minus"){
				sum-=stoi(strs[i+1]);
				i++;
			}
		}
		maxi=max(maxi,sum);
		mini=min(mini,sum);
		strs.clear();
		return;
	}
	if(a<signs[0]){
		v.push_back(0);
		solve(ind+1,a+1,b,c,d);
		v.pop_back();
	}
	if(b<signs[1]){
		v.push_back(-1);
		solve(ind+1,a,b+1,c,d);
		v.pop_back();
	}
	if(c<signs[2]){
		v.push_back(-2);
		solve(ind+1,a,b,c+1,d);
		v.pop_back();
	}
	if(d<signs[3]){
		v.push_back(-3);
		solve(ind+1,a,b,c,d+1);
		v.pop_back();
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	for(int i=0;i<4;i++){
		cin >> signs[i];
	}
	solve(0,0,0,0,0);
	cout << maxi << '\n' << mini;
}
