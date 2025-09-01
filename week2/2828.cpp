#include<bits/stdc++.h>
using namespace std;

int n,k;
int arr[110];
int s=1,e,cnt,length;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>e;
	
	cin>>k;
	
	for(int i=0;i<k;i++)
		cin>>arr[i];
	
	//한칸이동하고 비교하고 한칸이동하고 비교하고 반복하다
	//바스켓에 닿으면 다음 분기로 이동시킴
	
	for(int i=0;i<k;i++){
		int apple=arr[i];
		//cout<<apple<<'\n';
		if(apple>e){
			int len=apple-e;
			cnt+=len;
			e+=len;
			s=s+len;
		}
		
		else if(apple<s){
			int len=s-apple;
			cnt+=len;
			e=e - len;
			s=s-len;
		}
		
	}	
	 
	
	cout<<cnt;
	
	return 0;
}