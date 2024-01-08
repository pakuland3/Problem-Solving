#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int graph[10001][101];

void dfs(){
	
}

int main(){
	cin >> N >> M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%1d", &graph[i][j]);
		}
	}
	dfs();
	
}
