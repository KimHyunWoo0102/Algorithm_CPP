#include<bits/stdc++.h>
using namespace std;

int arr[3][3],visited[3][3];

int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

void go(int y,int x){
	visited[y][x]=1;
	
	cout<<y<<" : "<<x<<endl;
	
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		if(nx<0||nx>=3||ny<0||ny>=3)
			continue;
			
		if(visited[ny][nx]==1)
			continue;
		if(arr[ny][nx]==0)continue;		
		go(ny,nx);
	}
}
int main(){
	ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			cin>>arr[i][j];
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(!visited[i][j]&&arr[i][j])
				go(i,j);
		}
	}
	return 0;
}