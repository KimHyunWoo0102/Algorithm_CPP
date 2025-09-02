#include<bits/stdc++.h>
using namespace std;

#define MAX_LEN 10004

vector<int> adj[MAX_LEN];
int n,m;
int from,to;
int cnt;

vector<pair<int,int>>v;

void dfs(int parent){
	for(auto it:adj[parent]){
		cnt++;	
		dfs(it);
	}
}

bool cmp(pair<int,int>p1,pair<int,int>p2){
	if(p1.second==p2.second)
		return p1.first<p2.first;
	return p1.second>p2.second;
}
int max_cnt;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	
	for(int i=0;i<m;i++){
		cin>>to>>from;
		adj[from].push_back(to);		
	}	
	
	for(int i=1;i<=n;i++){
		cnt=0;
		dfs(i);
		max_cnt=max(cnt,max_cnt);
		v.push_back({i,cnt});		
	}	
	
	for(auto it:v){
		if(it.second==max_cnt)
			cout<<it.first<<" ";
	}
	
	return 0;
}