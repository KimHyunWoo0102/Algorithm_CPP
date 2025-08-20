#include<bits/stdc++.h>
using namespace std;

int arr[30];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	string str;
	cin>>str;
	
	for(char ch:str){
		arr[ch-'a']++;
	}	
	
	
	for(int i=0;i<26;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}