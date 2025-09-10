#include<bits/stdc++.h>
using namespace std;

int n;
int people[15],visited[15];
vector<int>adj[15];

int start1,start2;

int ret1,ret2,ret=INT_MAX;

void dfs0(int now,int num){
	visited[now]=1;
	ret1+=people[now];
	
	for(auto next:adj[now]){
		if(visited[next])continue;
		if(num&(1<<next)){
			dfs0(next,num);
		}
	}
}

void dfs1(int now,int num){
	visited[now]=1;
	ret2+=people[now];
	
	for(auto next:adj[now]){
		if(visited[next])continue;
		if(!(num&(1<<next))){
			dfs1(next,num);
		}
	}
}

bool check(){
	for(int i=0;i<n;i++){
		if(!visited[i])return false;
	}
	return true;
}

void print(){
	for(int i=0;i<n;i++){
		cout<<visited[i];
	}
	cout<<"\n\n";
}

void find_start_idx(int num){	
	for(int i=0;i<n;i++){
		if((num&(1<<i))){
			start1=i;
			break;
		}
	}
	
	for(int i=0;i<n;i++){
		if(!(num&(1<<i))){
			start2=i;
			break;
		}
	}
	
	
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>people[i];
		
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		
		for(int j=0;j<t;j++){
			int tmp;
			cin>>tmp;
			adj[i].push_back(tmp-1);
		}
	}
	
	for(int i=1;i<(1<<n);i++){
		//check all cases
		memset(visited,0,sizeof(visited));
		find_start_idx(i);
		ret1=ret2=0;
		
		dfs0(start1,i);
		dfs1(start2,i);
		
		if(check()){
			ret=min(ret,abs(ret1-ret2));
		}
	}
	
	if(ret==INT_MAX)
		cout<<-1;
	else
		cout<<ret;
	return 0;
}