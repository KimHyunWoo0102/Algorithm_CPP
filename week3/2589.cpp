#include<bits/stdc++.h>
using namespace std;

int n,m;
char arr[54][54];
int visited[54][54];
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

vector<pair<int,int>> L;
int ret=0;
int bfs(int y,int x){
	memset(visited,0,sizeof(visited));
	
	int dist=0;
		
	visited[y][x]=1;
	queue<pair<int,int>> q;
	
	q.push({y,x});
	
	while(q.size()){
		tie(y,x)=q.front();q.pop();
		
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(ny<0||nx<0||ny>=n||nx>=m)continue;
			if(visited[ny][nx])continue;
			if(arr[ny][nx]!='L')continue;
			
			visited[ny][nx]=visited[y][x]+1;
			q.push({ny,nx});		
			dist=max(dist,visited[ny][nx]);
		}
	}	
	return dist;
}
int main(){
	scanf("%d %d",&n,&m);	
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf(" %c",&arr[i][j]);
			if(arr[i][j]=='L')L.push_back({i,j});
		}
	}
	int len=L.size();
	
	for(int i=0;i<len;i++){
		ret=max(ret,bfs(L[i].first,L[i].second));
	}
	
	cout<<ret-1;
	
	return 0;
}
