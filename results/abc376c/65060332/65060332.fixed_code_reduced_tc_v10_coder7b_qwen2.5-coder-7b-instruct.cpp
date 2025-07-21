#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N],b[N];
int main(){
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<n;i++){
		cin>>b[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n);
	ll l=1,r=n;
	while(l<r){
		ll mid=(l+r)>>1;
		bool flag=true;
		vector<ll> cnt(n,0);
		for(ll i=1;i<=n-1;i++){
			cnt[b[i]/mid]++;
			if(cnt[b[i]/mid]>1){
				flag=false;
				break;
			}
		}
		if(flag){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	if(r==n){
		cout<<-1;
	}
	else{
		cout<<r;
	}
	return 0;
}