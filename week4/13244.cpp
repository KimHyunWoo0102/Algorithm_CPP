#include<bits/stdc++.h>
using namespace std;

int t,m,n;
int from,to;
int cnt;

vector<int>adj[1004];
int visited[1004];

bool check(){
	for(int i=1;i<=n;i++){
		if(visited[i]==0){
			return false;
		}
	}
	return true;
}
void go(int now){
	visited[now]=1;
	
	for(auto next:adj[now]){
		if(!visited[next])
			go(next);
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>t;
	
	for(int i=0;i<t;i++)
	{
		cin>>n>>m;
		memset(visited,0,sizeof(visited));
		for(int j=0;j<m;j++){
			cin>>from>>to;
			
			adj[from].push_back(to);
			adj[to].push_back(from);
		}
		if(n-1==m){
			go(1);
			if(check()){
				cout<<"tree\n";
			}else{
				cout<<"graph\n";
			}
		}else{
			cout<<"graph\n";
		}
		
		for(int j=1;j<=n;j++){
			adj[j].clear();
		}
		
	}	
	return 0;
}