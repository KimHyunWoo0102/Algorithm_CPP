#include<bits/stdc++.h>
using namespace std;

int n,m,cnt;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int arr[104][104],visited[104][104];

void dfs(int y,int x){
	visited[y][x]=1;
	
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		if(ny<0||nx<0||ny>=n||nx>=m)
			continue;
		if(arr[ny][nx]==0)continue;
		if(visited[ny][nx])continue;
		
		dfs(ny,nx);
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cin>>arr[i][j];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!visited[i][j]&&arr[i][j]==1)
			{
				dfs(i,j);
				cnt++;
			}
		}
	}
	
	cout<<cnt;
	return 0;
}