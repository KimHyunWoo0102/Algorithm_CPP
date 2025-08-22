#include<bits/stdc++.h>
using namespace std;

char prev;
int cnt;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	string str;
	int n;
	
	cin>>n;
	
	for(int i=0;i<n;i++){
		stack<char> s;
		cin>>str;
		
		for(char ch:str){
			if(!s.empty()&&s.top()==ch){
				s.pop();
			}else{
				s.push(ch);
			}
		}
		
		if(s.empty()){
			cnt++;
		}
	}
	
	cout<<cnt;
	return 0;
}