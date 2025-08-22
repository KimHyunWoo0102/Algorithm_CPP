#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
long long a,b,c;

ll run(ll x,ll y){
	if (y == 0) return 1; // base case

    ll half = run(x, y / 2);
    half = (half * half) % c;

    if (y % 2 == 1) {
        return (half * (x % c)) % c;
    } else {
        return half;
    }
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>a>>b>>c;
	
	int ret = run(a,b);
	
	cout<<ret%c;
	return 0;
}