#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int n;
ll c;

map<ll,int> m;
map<ll,int> o;
vector<ll> v;

bool cmp(ll d1,ll d2){
	if(m[d1]==m[d2])
		return o[d1]<o[d2];
	return m[d1]>m[d2];
}
int main(){
	//입력된순서 저장 필요
	//빈도수 저장 필요 
	cin>>n>>c;
	ll tmp;
	for(int i=0;i<n;i++){
		cin>>tmp;
		
		m[tmp]++;
		if(o[tmp]==0)
			o[tmp]=i+1;
		v.push_back(tmp);
	}
	

	sort(v.begin(),v.end(),cmp);
	
	for(auto it:v)
		cout<<it<<" ";
	return 0;
}
