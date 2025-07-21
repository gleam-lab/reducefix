#include<bits/stdc++.h>
using namespace std;
int n,q,x[200005],p[200005];
map<long long,long long>sum;
int main(){
	cin>>n;
    for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
	     sum[x[i]]=sum[x[i]]+p[i];
	}
	cin>>q;
	while(q--){
		long long L,R;
		cin>>L>>R;
	   auto it_l = sum.lower_bound(L);
	   auto it_r = sum.upper_bound(R);
	   if(it_l==sum.end() || it_r==sum.begin()) {
	       cout<<"0"<<endl;
           continue;
       }
       --it_r;
	   cout<<(it_r->second-it_l->second)<<endl;	
	}
}