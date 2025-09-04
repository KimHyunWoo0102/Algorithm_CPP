#include<bits/stdc++.h>
using namespace std;

#define MAX_LEN 100004
int n,k;
int visited[MAX_LEN],cnt[MAX_LEN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	visited[n]=1;
	cnt[n]=1;
	queue<int> q;
	q.push(n);
	
	while(q.size()){
		int pos=q.front();q.pop();
		
		for(int npos:{pos-1,pos+1,pos*2}){
			if(npos<0||npos>=MAX_LEN)continue;
			
			if(!visited[npos]){
				visited[npos]=visited[pos]+1;
				q.push(npos);
				cnt[npos]+=cnt[pos];
			}else if(visited[npos]==visited[pos]+1){
				cnt[npos]+=cnt[pos];
			}
		}
	}	
	
	
	cout<<visited[k]-1<<'\n'<<cnt[k];
	return 0;
}