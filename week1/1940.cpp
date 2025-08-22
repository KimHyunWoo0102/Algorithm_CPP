#include<bits/stdc++.h>
using namespace std;

int arr[15004];
int cnt;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int n,m;
	
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]+arr[j]==m){
				cnt++;
			}			
		}
	}
	
	cout<<cnt;
	return 0;
}