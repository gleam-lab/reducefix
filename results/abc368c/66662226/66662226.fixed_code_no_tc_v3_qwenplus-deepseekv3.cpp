#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

ll calculate_attacks(ll h) {
    ll low = 0, high = 2 * h;
    while (low < high) {
        ll mid = (low + high) / 2;
        ll damage = mid + mid / 3;
        if (damage >= h) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    vector<ll> required(n);
    rep(i, n) {
        required[i] = calculate_attacks(h[i]);
    }
    ll max_T = *max_element(required.begin(), required.end());
    cout << max_T << endl;
    return 0;
}