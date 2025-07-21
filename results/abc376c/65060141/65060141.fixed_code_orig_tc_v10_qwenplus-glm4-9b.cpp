#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N],b[N];
int main(){
	ll n,cnt=0,ans=0,mx=0;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	for(ll i=0;i<n-1;i++){
		cin>>b[i];
	}
	sort(a,a+n);
	sort(b,b+n-1);
	ll l=0,r=n-1;
	ll mid;
	while(l<=r){
		mid=(l+r)/2;
		bool possible=true;
		for(ll i=0;i<n;i++){
			if(a[i]>b[mid]){
				possible=false;
				break;
			}
		}
		if(possible){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	if(l>=n-1){
		cout<<-1;
		return 0;
	}
	cout<<l;
	return 0;
}