#include<bits/stdc++.h>
using namespace std;

string str,ret;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	getline(cin,str);
	
	for(char ch:str){
		if('a'<=ch&&ch<='z'){
			ret+= (ch-'a'+13)%26+'a';	
		}else if('A'<=ch&&ch<='Z'){
			ret+=(ch-'A'+13)%26+'A';
		}else
			ret+=ch;
	}
	
	cout<<ret;

	return 0;
}