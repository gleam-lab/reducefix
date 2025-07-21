#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, ans = 0, tri = 1;
    cin >> n;
    vector<ll> h(n);
    for(ll &hi: h) cin >> hi;

    for(ll &hi: h) {
        while(hi > 0) {
            if(tri == 3) {
                hi -= 3;
                ans++;
            } else {
                hi -= 1;
                ans++;
            }
            tri++;
            if(tri > 3) tri = 1;
        }
    }

    cout << ans;
}