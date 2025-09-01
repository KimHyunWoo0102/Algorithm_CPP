#include<bits/stdc++.h>
using namespace std;

bool go(string&str){
	stack<char> s;
	
	for(char c: str){
		if(c=='('||c=='[')s.push(c);
		else if(c==')'){
			if(s.empty()||s.top()!='(')return false;
			else s.pop();
		}
		else if(c==']'){
			if(s.empty()||s.top()!='[')return false;
			else s.pop();
		}
	}
	
	return !s.size();
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	string str;
	while(getline(cin,str)){
		//cout<<str<<'\n';
		if(str==".")break;
		         
		if(go(str))cout<<"yes\n";
		else cout<<"no\n";	
	}
	return 0;
}