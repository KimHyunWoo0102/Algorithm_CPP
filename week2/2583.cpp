#include<bits/stdc++.h>
using namespace std;

#define y1 sdadsawd
int n,m,r;
//y=n,x=m

vector<int> v;

int arr[104][104],visited[104][104];
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
int x1,y1,x2,y2;
int cnt;

void print(int p[104][104],int y,int x){
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++)
			cout<<p[i][j];
		cout<<'\n';
	}
}

void dfs(int y,int x){
	visited[y][x]=1;
	cnt++;
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		if(ny<0||nx<0||nx>=m||ny>=n)continue;
		if(arr[ny][nx]==1)continue;
		if(visited[ny][nx]==1)continue;
		
		dfs(ny,nx);	
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>m>>r;
	
	for(int i=0;i<r;i++){
		cin>>x1>>y1>>x2>>y2;
		
		for(int i=y1;i<y2;i++){
			
			for(int j=x1;j<x2;j++){
				arr[i][j]=1;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(visited[i][j]==0&&arr[i][j]==0){
				cnt=0;
				dfs(i,j);
				v.push_back(cnt);
			}
		}
	}
	
	sort(v.begin(),v.end());
	
	cout<<v.size()<<'\n';
	for(auto it : v){
		cout<<it<<' ';
	}
	return 0;
}