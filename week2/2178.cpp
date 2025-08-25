#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[104][104];
int visited[104][104];

int y,x;
int dy[]={0,1,0,-1},dx[]={-1,0,1,0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	string input;
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		cin>>input;
		
		for(int j=0;j<m;j++)
			arr[i][j]=input[j]-'0';
	}
	
	queue<pair<int,int>>q;
	
	q.push({0,0});
	visited[0][0]=1;
	
	while(q.size()){
		tie(y,x)=q.front();
		q.pop();
	
		for(int i=0;i<4;i++){
			int ny=y+dy[i];
			int nx=x+dx[i];
	
			if(ny<0||nx<0||nx>=m||ny>=n)continue;
			if(arr[ny][nx]==0||visited[ny][nx])continue;
			visited[ny][nx]=visited[y][x]+1;

			q.push({ny,nx});
		}
	}
	
	cout<<visited[n-1][m-1];
	return 0;
}