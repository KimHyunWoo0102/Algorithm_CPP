#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;

ll pow_m(int x,int y){
	if (y == 0) return 1;   // x^0 = 1
	if (y == 1) return x % n;  // x^1 = x mod n
	
	int ret=pow_m(x,y/2);
	
	ret=(ret%n)*(ret%n)%n;
	
	if(y%2==1){
		ret=x%n*ret%n;
	}
	return ret;
}

ll run(){
	ll sum=0;
	ll cnt=0;
	for(int i=0;;i++){
		cnt++;
		//cout<<"run() = "<<(int)(pow_m(i))<<"\n";
		sum=(sum+(int)(pow_m(10,i)))%n;
		//cout<<"sum = "<<sum<<"\n";
		
		if(sum%n==0)
			return cnt;
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	while(cin>>n){
		//(a+b)%c=a%c+b%c
		//(a*b)%c=a%c*b%c
		//11111 = 1000+100+10+1 recursive sum
		//11111 = 1111*10 + 1 <- not recursive  much easier
		//sum(10^n%c)%c==0
		cout<<run()<<'\n';	
	}
	return 0;
}