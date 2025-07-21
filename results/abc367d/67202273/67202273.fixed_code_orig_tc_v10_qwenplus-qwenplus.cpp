#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 4e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Since all elements are the same, and we're looking for subarrays whose sum mod m == 0,
    // any subarray of length k will have sum = k * a[0], so we need k * a[0] mod m == 0.
    // For this to be true for all cyclic rotations, let's analyze this.

    ll val = a[0];
    ll g = gcd(val, m);

    // We want number of k in [1, 2n] such that k * val mod m == 0
    // This is equivalent to k divisible by m / gcd(val, m)

    ll period = m / g;

    // Total subarrays across double array is 2n, but we only consider those of length <= n
    ll total = 0;
    for (ll k = 1; k <= 2 * n; ++k) {
        if (k % period == 0) {
            // count how many starting positions are valid
            ll start_limit = min(k, n);
            if (k <= n) {
                total += k;
            } else {
                total += 2 * n - k + 1;
            }
        }
    }

    cout << total << "\n";

    return 0;
}