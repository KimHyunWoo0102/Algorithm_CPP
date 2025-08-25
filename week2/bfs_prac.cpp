#include<bits/stdc++.h>
using namespace std;   

int n,m;
int arr[104][104];
int visited[104][104];

int sx,sy,ex,ey;

int dy[]={0,1,0,-1},dx[]={-1,0,1,0};

void bfs(int y,int x){
	visited[y][x]=1;
	
	queue<pair<int,int>> q;
	
	q.push({y,x});
	
	while(q.size()!=0){
	
		tie(y,x)=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int ny=y+dy[i];
			int nx=x+dx[i];
		
			if(ny<0||nx<0||ny>=n||nx>=m)continue;
			if(visited[ny][nx])continue;
			if(arr[ny][nx]==0)continue;

			visited[ny][nx]=visited[y][x]+1;
			q.push({ny,nx});
			
	}	
}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>m;
	
	cin>>sx>>sy;
	cin>>ex>>ey;	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)cin>>arr[i][j];
	}	
	
	bfs(sx,sy);
	
	cout<<visited[ey][ex];
	return 0;
}