#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N],b[N];
int main(){
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++) cin>>a[i];
	for(ll i=0;i<n-1;i++) cin>>b[i];
	sort(a,a+n);
	sort(b,b+n-1);
	ll l=0,r=0;
	ll cnt=0,mx=0;
	while(l<n && r<n-1){
		if(b[r]>=a[l]){
			r++;
			l++;
		}
		else{
			mx=max(mx,a[l]);
			l++;
			cnt++;
		}
	}
	if(cnt>1){
		cout<<-1;
		return 0;
	}
	cout<<mx;
	return 0;
}