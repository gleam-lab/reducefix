#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n, ans=0, tri=1;
    cin>>n;
    vector<ll> h(n);
    for(int i=0;i<n;i++) {
        cin>>h[i];
    }
    sort(h.begin(), h.end());
    reverse(h.begin(), h.end());
    for(auto& x: h) {
        while(x > 0) {
            if(tri % 3 == 0) {
                x -= 3;
                ans++;
            } else {
                x -= 1;
                ans++;
            }
            tri++;
        }
    }
    cout<<ans;
}