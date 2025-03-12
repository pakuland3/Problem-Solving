#include <bits/stdc++.h>
using namespace std;

vector<int> order,graph,idx;
int n,m,k,FUCK=-1;

int solve(int des){
	if(FUCK!=-1 && FUCK!=0 && idx[order[FUCK-1]] && des<idx[order[FUCK-1]]) return 0;
	if(FUCK!=-1 && FUCK!=m-1 && idx[order[FUCK+1]] && des>idx[order[FUCK+1]]) return 0;
    graph[des]=1;
    idx[1]=des;
    int i=0;
    int cnt=0;
    for(int j=1;j<=n;j++){
    	if(graph[j]){
            cnt++;
            continue;
        }
    	if(i==m-1) return 1;
		if(idx[order[i]]){
			i++;
			j--;
			continue;
		}
		if(i!=0 && idx[order[i-1]] && j<idx[order[i-1]]) continue;
		if(i!=m-1 && idx[order[i+1]] && j>idx[order[i+1]]){
    		graph[des]=0;
	    	idx[1]=0;
			return 0;
		}
		i++;
	}
	graph[des]=0;
	idx[1]=0;
    return i==m || cnt==n;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("in_out/10.in","r",stdin);
    cin >> n >> m >> k;
    order.resize(m,0);
    graph.resize(n+1,0);
    idx.resize(n+1,0);
    for(int i=0;i<m;i++){
    	cin >> order[i];
    	if(order[i]==1) FUCK=i;
	}
    for(int i=0;i<k;i++){
        int a,b;
        cin >> a >> b;
        if(a==1){
            cout << b;
            return 0;
        }
        idx[a]=b;
        graph[b]=a;
    }
    // freopen("in_out/10.out","r",stdin);
    // int ans;
    // cin >> ans;
    for(int i=1;i<=n;i++){
        if(!graph[i] && solve(i)){
            // cout << (i==ans);
            cout << i;
            return 0;
        }
    }
    return 0;
}