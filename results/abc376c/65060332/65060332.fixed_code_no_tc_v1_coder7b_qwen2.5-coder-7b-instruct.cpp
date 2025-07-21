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
	ll l=n,r=n-1;
	ll ans = -1;
	while(l>=1){
		if(r>=1 && b[r]>=a[l]){
			r--;
			l--;
		}
		else{
			ans = max(ans, a[l]);
			l--;
		}
	}
	cout<<ans;
	return 0;
}