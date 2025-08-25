#include<bits/stdc++.h>
using namespace std;

#define y1 sasd

int r,n,m,k;
int x1,y1;

const int max_size=54;
int arr[max_size][max_size];
int visited[max_size][max_size];

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void print(int parr[][max_size],int y,int x){
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++)
			cout<<parr[i][j];
		cout<<'\n';
	}
}

void dfs(int y,int x){
	visited[y][x]=1;
	
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		if(nx<0||ny<0||nx>=m||ny>=n)continue;
		if(visited[ny][nx]==1)continue;
		if(arr[ny][nx]==0)continue;
		
		dfs(ny,nx);		
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);	

	cin>>r;
	
	for(int i=0;i<r;i++){
		cin>>m>>n>>k;
		int cnt=0;
		
		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));
		
		for(int j=0;j<k;j++){
			cin>>x1>>y1;
			arr[y1][x1]=1;
		}
		
		//print(arr,n,m);
		for(int j=0;j<n;j++){
			for(int l=0;l<m;l++){
				if(!visited[j][l]&&arr[j][l])
				{
					cnt++;
					dfs(j,l);
				}
			}
		}
		
		cout<<cnt<<'\n';
	}
	return 0;
}