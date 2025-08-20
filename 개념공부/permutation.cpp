#include<bits/stdc++.h>
using namespace std;

void printV(const vector<int> &v,int r=3){
	for(int i=0;i<r;i++){
		cout<<v[i]<<' ';
	}
	cout<<'\n';
}

void printA(const int v[], int size){
    for(int i=0;i<size;i++){
        cout<<v[i]<<' ';
    }
    cout<<'\n';
}

//comment error

bool comp(int i1,int i2){
	return i1>i2;
}

int main(){
	int a[3]={1,2,3};
	vector<int> v;
	
	for(int i=0;i<3;i++)
	{
		v.push_back(a[i]);
	}
	
	do{
		printV(v,2);
	}while(next_permutation(v.begin(),v.end()));
	
	printV(v);
	cout<<'\n';
	
	sort(v.begin(),v.end(),comp);
	
	do{
		printV(v);
	}while(prev_permutation(v.begin(),v.end()));
	do{
		printA(a,3);
	}while(next_permutation(a,a+3));
	return 0;
}