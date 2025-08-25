#include<bits/stdc++.h>
using namespace std;

int s,cnt;

int n;
string str;
int main(){
	//ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
	
	cin>>n;
	vector<string> v;
	for(int i=0;i<n;i++){		
		cin>>str;

		cnt=0;
		s=0;
		for(int j=0;j<str.size();j++){
			if(isdigit(str[j])){
				if(cnt==0)
					s=j;
				cnt++;
			}else{
				if(cnt!=0){
					v.push_back(str.substr(s,cnt));
					cnt=0;
				}
			}
		}
		
		if(cnt!=0){
			v.push_back(str.substr(s,cnt));
			cnt=0;
		}
	}
	sort(v.begin(),v.end());
	
	for(auto it:v)
		cout<<it<<'\n';
	return 0;
}
