#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); i++)
using ll = long long;

int main() {
    int n; cin >> n;
    ll ans = 0;
    vector<ll> h(n);
    rep(i, n) {
        cin >> h[i];
        ll temp1 = h[i] / 5;
        ll temp2 = h[i] % 5;

        // For each enemy, calculate the total number of hits required.
        // temp1 * 3 gives us the number of hits that are guaranteed to be multiples of 3.
        // temp2 gives us the number of hits that are not multiples of 3.
        ans += temp1 * 3 + temp2;
    }
    cout << ans << endl;
}