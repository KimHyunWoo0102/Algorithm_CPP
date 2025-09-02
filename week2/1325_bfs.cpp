#include<bits/stdc++.h>
using namespace std;

#define MAX_LEN 10004

vector<int> adj[MAX_LEN];
vector<pair<int,int>> v;
int n,m;
int from,to;

bool cmp(pair<int,int>p1,pair<int,int>p2){
	if(p1.second==p2.second)
		return p1.first<p2.first;
	return p1.second>p2.second;
}
int max_cnt;

int visited[MAX_LEN];

int bfs(int start){
	memset(visited,0,sizeof(visited));
	queue<int>q;
	int cnt=1;
	q.push(start);
	visited[start]=1;
	
	while(q.size()){
		int current=q.front();q.pop();
		
		for(auto next:adj[current]){
			if(visited[next]==1)continue;
			cnt++;
			q.push(next);
			visited[next]=1;
		}
	}
	
	return cnt;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	
	for(int i=0;i<m;i++){
		cin>>to>>from;
		adj[from].push_back(to);		
	}	
	
	for(int i=1;i<=n;i++){
		int cnt = bfs(i);
		v.push_back({i,cnt});
		max_cnt=max(cnt,max_cnt);
	}	
	
	for(auto& it:v){
		if(it.second==max_cnt)
			cout<<it.first<<" ";
	}
	
	return 0;
}