#include<bits/stdc++.h>
using namespace std;

string str,ret;
int cnt;
char ch;
map<char,int>m;

bool is_p(string& s) {
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>str;
	
	for(char ch:str)
		m[ch]++;
		
	for(auto it:m){
		if(it.second%2==1)
		{
			ch=it.first;
			cnt++;
			if(cnt==2){
				cout<<"I'm Sorry Hansoo";
				exit(-1);
			}
		}
	}	
	
			
	for(auto it:m){
		ret+=string(it.second/2,it.first);
	}
	
	if(ch)
		cout<<ret<<ch;
	else
		cout<<ret;
	reverse(ret.begin(),ret.end());
	cout<<ret;
	return 0;
}