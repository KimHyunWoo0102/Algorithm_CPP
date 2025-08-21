#include<bits/stdc++.h>

using namespace std;

int n,k;
int arr[100004];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>k;
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	int max=0;
	int sum=0;
	
	for(int i=0;i<n;i++){
		if(i<k){
			sum+=arr[i];
			max=sum;
		}else{
			sum+=-arr[i-k]+arr[i];
			max=sum>max?sum:max;
		}
	}
	
	cout<<max;
	
}