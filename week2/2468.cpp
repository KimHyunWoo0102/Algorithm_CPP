#include<bits/stdc++.h>
using namespace std;

int n;
int arr[104][104],visited[104][104];
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

void dfs(int y,int x,int h){
	visited[y][x]=1;
	
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		if(ny<0||nx<0||ny>=n||nx>=n)continue;
		if(visited[ny][nx])continue;
		if(arr[ny][nx]<=h)continue;		
		
		dfs(ny,nx,h);
	}
}

int ret;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	}	
	
	for(int i=1;i<=100;i++){
		int cnt=0;
		memset(visited,0,sizeof(visited));
		
		for(int sy=0;sy<n;sy++){
			for(int sx=0;sx<n;sx++){
				if(visited[sy][sx]==0&&arr[sy][sx]>i)
				{
					cnt++;
					dfs(sy,sx,i);
				}
			}
		
		ret=ret>cnt?ret:cnt;
		}
	
	}
	cout<<ret;
}