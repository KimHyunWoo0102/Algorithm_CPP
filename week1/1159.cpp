#include<bits/stdc++.h>
using namespace std;

int cnt[26];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	bool flag=false;
	string str;
	string PREDAJA="PREDAJA";
	
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>str;
		cnt[str[0]-'a']++;
	}
	
	for(int i=0;i<26;i++){
		if(cnt[i]>=5){
			cout<<char(i+'a');
			flag=true;
		}
	}	
	
	if(!flag)
		cout<<PREDAJA;
	return 0;
}