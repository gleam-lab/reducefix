#include<bits/stdc++.h>
using namespace std;
int n,q,x[200005],p[200005];
long long sum[200005]; // Changed to long long to handle larger sums
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
	    l=lower_bound(x+1,x+n+1,l)-x; // Corrected from x+1 to x
	    r=upper_bound(x+1,x+n+1,r)-x; // Corrected from x+1 to x
		cout<<(sum[r]-sum[l])<<endl; // Removed unnecessary -1 as r is already exclusive
	}
	return 0;
}