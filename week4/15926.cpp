#include<bits/stdc++.h>
using namespace std;

int ret,cnt,n;
string str;

bool visited[200004];

int main(){
	cin>>n;
	cin>>str;
	
	stack<int> s;
	
	for(int i=0;i<n;i++){
		if(str[i]=='('){
			s.push(i);
		}else if(str[i]==')'){
			if(s.size()){
				visited[i]=true;
				visited[s.top()]=true;
				s.pop();
			}
		}
	}
	
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(visited[i]){
			cnt++;
		}else{
			ret=max(cnt,ret);
			cnt=0;
		}
	}
	
	cout<<ret;
	
	return 0;
}