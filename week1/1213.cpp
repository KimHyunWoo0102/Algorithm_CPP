#include<bits/stdc++.h>
using namespace std;

string str,ret;

bool is_p(string& s) {
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>str;
	
	sort(str.begin(),str.end());
	
	do{
		if(is_p(str)){
			cout<<str;
			exit(0);
		}
	}while(next_permutation(str.begin(),str.end()));
			
	cout<<"I'm Sorry Hansoo";
	return 0;
}