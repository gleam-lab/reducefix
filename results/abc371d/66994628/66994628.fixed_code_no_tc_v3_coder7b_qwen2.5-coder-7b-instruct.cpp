#include<bits/stdc++.h>
using namespace std;
int n,q,x[200005],p[200005];
long long sum[200005]; // Changed int to long long to handle large sums
int main(){
	cin>>n;
    for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
	     sum[i]=sum[i-1]+p[i];
	}
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
	    l=lower_bound(x+1,x+n+1,l)-x; // Corrected index to start from 1
	    r=upper_bound(x+1,x+n+1,r)-x; // Corrected index to start from 1
		if(l <= n && r <= n) // Check if indices are within bounds
			cout<<(sum[r]-sum[l-1])<<endl;	
		else 
			cout<<"0\n"; // Handle out-of-bound queries gracefully
	}
}