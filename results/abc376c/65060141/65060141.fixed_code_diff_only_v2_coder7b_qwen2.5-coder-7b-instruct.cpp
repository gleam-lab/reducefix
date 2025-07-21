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
	ll ans = max(*max_element(a+1,a+n), *max_element(b+1,b+n));
	bool valid = true;
	for(int i=1; i<=n-1; i++) {
        if(a[i] > b[i]) {
            valid = false;
            break;
        }
    }
	if(valid) cout << ans;
	else cout << -1;
	return 0;
}