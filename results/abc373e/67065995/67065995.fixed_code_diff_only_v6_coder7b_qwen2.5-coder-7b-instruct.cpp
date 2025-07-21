#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort indices based on vote counts
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return a[i] > a[j]; });

    // Calculate prefix sums for sorted vote counts
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[idx[i]];
    }

    // Initialize result array
    vector<ll> res(n, -1);

    for (int i = 0; i < n; ++i) {
        int target = min(m, n - i); // Number of candidates that can surpass candidate i
        ll need = 0;

        // Binary search to find the minimum additional votes needed
        ll lo = 0, hi = k + 1;
        while (lo < hi) {
            ll mid = (lo + hi) / 2;
            ll extra_votes = mid * target - (pref[min(n, i + target)] - pref[i]);

            if (extra_votes > k) {
                hi = mid;
            } else {
                need = mid;
                lo = mid + 1;
            }
        }

        // Check if the calculated need is valid
        if (need <= k) {
            res[idx[i]] = need;
        }
    }

    // Output the results
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}