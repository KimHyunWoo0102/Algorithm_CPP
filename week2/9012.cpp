#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int n;
	string str;
	
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>str;
		stack<char> s;
		bool f=true;	
		for(char c:str){
			if(c=='(')s.push(c);
			else if(c==')'&&s.empty())f=false;
			else if(c==')')s.pop();	
		}
		
		if(!f||!s.empty())cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}