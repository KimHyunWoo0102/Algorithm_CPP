#include<bits/stdc++.h>
using namespace std;

const string vowel="aeiou";

bool is_a(string&str){
	int cnt=0;
	
	char prev=0;
	
	bool flag=false;
	
	for(char ch:vowel){
		if(str.find(ch)!=string::npos) flag=true;
	}
	
	if(flag==false)return flag;
		
	for(const char ch:str){
		if(prev==ch&&(ch!='o'&&ch!='e')){
			return false;
		}
		
		
		if(vowel.find(ch)!=string::npos&&vowel.find(prev)!=string::npos){
			cnt++;
			if(cnt>=3)return false;
		}
		else if(vowel.find(ch)==string::npos&&vowel.find(prev)==string::npos){
			cnt++;
			if(cnt>=3)return false;
		}else
			cnt=1;
			
		prev=ch;
	}
	
	return true;
}
int main(){
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	string input;
	
	while(cin>>input){
		if(input=="end")break;
		
		if(is_a(input))
			cout<<"<"<<input<<"> is acceptable.\n";
		else
			cout<<"<"<<input<<"> is not acceptable.\n";
	}
	
	return 0;
}
