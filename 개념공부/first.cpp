#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v1;
    
    for(int i=0;i<10;i++)
    {
          v1.push_back(i);
    }   
    
    for(const auto& item:v1)
    {
    	cout<<item<<std::endl;
	}
    return 0;
}
