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
		sum[x[i]]=sum[x[i]]+p[i]; // Corrected: Directly add p[i] to the value of x[i]
	}
	cin>>q;
	while(q--){
		int L,R;
		cin>>L>>R;
		if(sum.find(L) != sum.end() && sum.find(R) != sum.end()){
			cout<<sum[R]-sum[L]<<endl; // Corrected: Directly subtract the sum at L from R
		} else {
			cout << "Error: One or both values not found in map." << endl; // Added error handling for missing keys
		}
	}
	return 0;
}