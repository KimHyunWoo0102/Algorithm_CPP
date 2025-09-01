#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[10][10],visited[10][10];
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

vector<pair<int,int>> v;
int max_cnt;


void print(){
	cout<<"cnt = "<<max_cnt<<'\n';
	cout<<"arr \n";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<'\n';
	}	
	
	cout<<"visited\n";
    for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<visited[i][j]<<" ";
		}
		cout<<'\n';
	}
}

void dfs(int y,int x){
	visited[y][x]=1;
	
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		if(nx<0||ny<0||ny>=n||nx>=m)continue;
		if(visited[ny][nx]!=0)continue;
		if(arr[ny][nx]==1)continue;
		
		dfs(ny,nx);
	}
}

void go(){
	memset(visited,0,sizeof(visited));
	int cnt=0;	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==2&&visited[i][j]==0){
				dfs(i,j);
			}
		}
	}
}

int cnt(){
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==0&&visited[i][j]==0)
				cnt++;
		}
	}
	
	return cnt;
}
int main(){
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			if(arr[i][j]==0)v.push_back({j,i});
		}
	}
	
	int len=v.size();
	
	for(int i=0;i<len;i++){
		arr[v[i].second][v[i].first]=1;
		for(int j=i+1;j<len;j++){
			arr[v[j].second][v[j].first]=1;
			for(int k=j+1;k<len;k++){
				arr[v[k].second][v[k].first]=1;
				go();
				max_cnt=max(max_cnt,cnt());
				arr[v[k].second][v[k].first]=0;
			}
			arr[v[j].second][v[j].first]=0;
		}
		arr[v[i].second][v[i].first]=0;
	}
	
	cout<<max_cnt<<'\n';
	return 0;
}