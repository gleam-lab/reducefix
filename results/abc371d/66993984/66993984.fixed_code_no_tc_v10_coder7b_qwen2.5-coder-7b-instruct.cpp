#include<bits/stdc++.h>
using namespace std;
int n,q,x[200005],p[200005];
map<int,int>sum;
int main(){
	cin>>n;
    for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
		sum[x[i]]+=p[i]; // Corrected to add p[i] to the sum of elements equal to x[i]
	}
	cin>>q;
	while(q--){
		int L,R;
		cin>>L>>R;
		int result = 0;
		for(auto it=sum.begin();it!=sum.end();++it){ // Iterate over all unique elements in x
			if(it->first >= L && it->first <= R){
				result += it->second; // Add their contribution to the result if within the range [L, R]
			}
		}
		cout<<result<<endl;	
	}
}