#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n, ans=0, tri=1;
    cin>>n;
    vector<ll> health(n);
    for(int i=0;i<n;i++) {
        cin>>health[i];
    }
    sort(health.begin(), health.end());
    for(ll &h: health) {
        ans+=(h+2)/3;
    }
    cout<<ans;
}