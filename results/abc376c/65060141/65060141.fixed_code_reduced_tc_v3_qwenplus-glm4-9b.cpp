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
	
	// Using a two-pointer technique to find the minimum `x`
	ll l = 1, r = n - 1;
	ll x = LLONG_MAX;
	while (l <= r) {
		if (a[l] <= b[r]) {
			// If the smallest toy can fit in the largest box used so far,
			// then `x` could be as small as the toy's size.
			x = min(x, a[l]);
			l++;
		} else {
			// If the smallest toy cannot fit in the largest box, 
			// we need a box larger than `b[r]`.
			x = min(x, b[r]);
			r--;
		}
	}
	
	// If `x` is still LLONG_MAX, it means no such `x` exists
	if (x == LLONG_MAX) {
		cout << -1;
	} else {
		// We need an additional box of size `x`, so we need `x + 1`
		cout << x + 1;
	}
	return 0;
}