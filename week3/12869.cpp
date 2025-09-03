#include<bits/stdc++.h>
using namespace std;

int mutal[6][3]={
	{9,3,1},{9,1,3},{3,1,9},{3,9,1},{1,3,9},{1,9,3}
};

int visited[63][63][63];
int pos[3];

typedef struct{
	int z;
	int y;
	int x;
}P;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>pos[i];
	
	visited[pos[0]][pos[1]][pos[2]]=1;
	
	queue<P> q;
	q.push({pos[0],pos[1],pos[2]});
	
	while(q.size()){
		int x,y,z;
		auto p=q.front();q.pop();
		x=p.x;
		y=p.y;
		z=p.z;
		
		for(int i=0;i<6;i++){
			int nx=x-mutal[i][0];
			int ny=y-mutal[i][1];
			int nz=z-mutal[i][2];
			
			if(nx<0)nx=0;
			if(ny<0)ny=0;
			if(nz<0)nz=0;
			
			if(visited[nz][ny][nx])continue;
			visited[nz][ny][nx]=visited[z][y][x]+1;
			q.push({nz,ny,nx});
		}
	}	
	
	cout<<visited[0][0][0];
		
			
	
	return 0;
}
