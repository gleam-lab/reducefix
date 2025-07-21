#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, ans = 0;
    cin >> n;
    vector<ll> H(n);
    for (ll i = 0; i < n; ++i) {
        cin >> H[i];
    }

    for (ll i = 0; i < n; ++i) {
        if (H[i] % 3 == 0) {
            ans += H[i] / 3;
        } else {
            ans += (H[i] / 3) + 1;
            H[i] %= 3;
        }
        if (H[i] > 0) {
            ans += H[i];
        }
    }

    cout << ans;
}