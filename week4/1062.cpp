#include<bits/stdc++.h>
using namespace std;

int n,k;

int words[52];
int ret=0,mask,num;
string str;
vector<char>v;

int check(int num){
	int cnt=0;
	for(int i=0;i<n;i++){
		int word=words[i];
		if((num&word)==word){
			cnt++;
		}
	}
	
	return cnt;
}
void go(int num,int cnt,int start)
{
	if(cnt==k){
		//do something
		ret=max(ret,check(num));
		return;
	}
	
	for(int i=start;i<='z'-'a';i++){
		int bit=(1<<i);
		
		if(!(num&bit)){
			go(num|bit,cnt+1,i+1);
		}
	}
	
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	
	if(k<5){
		cout<<0;
		return 0;
	}
	
	if(k==26){
		cout<<n;
		return 0;
	}
	
	
	for(char ch:{'a','t','i','c','n'}){
		int bit=(1<<(ch-'a'));
		num|=bit;	
	}
	
	for(int i=0;i<n;i++){
		cin>>str;
		
		for(auto ch:str)
		{
			int bit=1<<(ch-'a');
			words[i]|=bit;
			
		}
	}
	
	k-=5;
	go(num,0,0);
	
	cout<<ret;
	return 0;
}