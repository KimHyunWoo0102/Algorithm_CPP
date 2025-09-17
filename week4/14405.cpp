#include<bits/stdc++.h>
using namespace std;

char str[5010];
int n;
bool solve(){
	for(int i=0;i<n;i++){
		if(str[i]=='p'){
			if(str[i+1]!='i')return false;
			i++;
		}else if(str[i]=='k'){
			if(str[i+1]!='a')return false;
			i++;
		}else if(str[i]=='c'){
			if(!(str[i+1]=='h'&&str[i+2]=='u'))return false;
			i+=2;
		}else{
			return false;
		}
	}
	
	return true;
}
int main(){
	cin>>str;
	n=strlen(str);
	
	if(solve()){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
	return 0;
}