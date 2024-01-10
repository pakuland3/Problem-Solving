#include <bits/stdc++.h>
using namespace std;

int graph[1001][1001];
int visited[1001][1001][2];
int N;
int M;



int main(){
	scanf("%d %d", &N, &M);
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%1d", &graph[i][j]);
		}
	}
}
