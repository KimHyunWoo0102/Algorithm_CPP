#include<bits/stdc++.h>
using namespace std;

int ret,cnt,n;
string str;

int main(){
	cin>>str;
	
	stack<char> s;
	
	for(int i=0;i<n;i++){
		if(str[i]=='('){
			s.push(str[i]);
		}else if(str[i]==')'){
			if(s.size()&&s.top()=='('){
				cnt+=2;
				s.pop();
			}else{
				while(s.size()){
					s.pop();
				}
				
				ret=max(cnt,ret);
			}
		}
	}
	
	cout<<ret;
	return 0;
}