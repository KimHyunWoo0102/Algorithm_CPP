#include<bits/stdc++.h>
using namespace std;
#define MAX_LEN 100004
int visited[MAX_LEN];
stack<int>s;
int n,k;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>k;
	visited[n]=1;	
	
	queue<int>q;
	q.push(n);
	while(q.size()){
		int now=q.front();q.pop();
		
		for(int next:{now+1,now-1,now*2})
		{
			if(0<=next&&next<MAX_LEN){
				if(!visited[next]){
					visited[next]=visited[now]+1;
					q.push(next);
				}
			}
		}
	}
	
	s.push(k);
	int pivot=visited[k]-1;
	
	while(s.size()&&pivot>0){
		int now=s.top();
		
		if(visited[now-1]==pivot){
			pivot--;
			s.push(now-1);	
		}else if(visited[now+1]==pivot){
			pivot--;
			s.push(now+1);
		}else if(now%2==0&&visited[now/2]==pivot){
			pivot--;
			s.push(now/2);
		}
	}
	
	cout<<visited[k]-1<<'\n';
	while(s.size()){
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}