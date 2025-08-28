#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


ll t,n;

#define MAX_LEN 1000000002

ll t_cnt,f_cnt;



map<ll,pair<ll,ll>>m;
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>t;
	
	for(int i=0;i<t;i++){
		
		cin>>n;
		
		t_cnt=0;f_cnt=0;
			
		for(ll j=2;j<=n;j*=2){
			t_cnt+=n/j;
		}
			
		for(ll j=5;j<=n;j*=5){
			f_cnt+=n/j;
		}
		
		cout<<min(t_cnt,f_cnt)<<'\n';
		}	
	
	return 0;
}