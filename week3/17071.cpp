#include<bits/stdc++.h>
using namespace std;

#define MAX_LEN 500001

int n,k;
int ret=INT_MAX;
int s_visited[2][MAX_LEN],visited[MAX_LEN];

int main(){
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	
	s_visited[0][n]=visited[k]=1;	
	queue<int> q;
	q.push(n);
	
	int turn=0;
	if(n==k)
	{
		cout<<0;
		return 0;
	}
	
	while(q.size()){
		int qsize=q.size();
		for(int i=0;i<qsize;i++){
			int now=q.front();q.pop();
			for(int next:{now+1,now-1,now*2}){
				if(0<=next&&next<MAX_LEN){
					if(s_visited[(turn+1)%2][next]==0){
						s_visited[(turn+1)%2][next]=s_visited[turn][now]+1;
						q.push(next);
					}
				}
			}
		}
		turn=(turn+1)%2;
	}
	long long now=k;
	turn=1;
	for(long long i=1;;i++){
    	long long next_pos = now + i; // 미리 계산

	    if(next_pos > 500000){ 
    	    cout << -1;
       	 return 0;
    	}
    
   	 	visited[next_pos] = visited[now] + 1;
    	now = next_pos;
    
    	if(s_visited[turn][next_pos] != 0 && (visited[next_pos] >= s_visited[turn][next_pos])){
        
        	cout << i;
        	return 0;
    	}
    
    turn = (turn+1)%2;
}
	return 0;
}