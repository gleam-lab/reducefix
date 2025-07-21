#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Compute total remaining votes
    ll total_received = accumulate(all(a), ll(0));
    ll remaining = k - total_received;

    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int x, int y) { return a[x] < a[y]; });

    vector<ll> sorted_a = a;
    sort(all(sorted_a));

    vector<ll> suffix_sum(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        suffix_sum[i] = suffix_sum[i + 1] + sorted_a[i];
    }

    vector<ll> res(n, -1);

    for (int idx = 0; idx < n; idx++) {
        int i = ord[idx];
        ll ai = a[i];

        // Binary search on the minimum number of additional votes
        ll low = 0, high = remaining;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll target = ai + mid;

            // We need to ensure that at most M-1 candidates can have more than target

            // Find how many votes are needed to make top (M) candidates not exceed our target
            int l = 0, r = n - 1;
            int pos;
            // Find rightmost index where sorted_a[pos] <= target
            while (l <= r) {
                int m2 = (l + r) / 2;
                if (sorted_a[m2] <= target) {
                    pos = m2;
                    l = m2 + 1;
                } else {
                    r = m2 - 1;
                }
            }

            int needed = n - (pos + 1); // How many are > target

            if (needed < m) {
                // Already good, we're in top M
                res[i] = 0;
                answer = 0;
                high = mid - 1;
                continue;
            }

            // Need to cap top (needed) candidates to <= target
            ll extra_needed = 0;
            int cnt = 0;
            for (int j = n - 1; j >= 0 && cnt < needed; j--, cnt++) {
                if (sorted_a[j] <= target)
                    break;
                extra_needed += max(0LL, sorted_a[j] - target);
            }

            if (extra_needed <= remaining - mid) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        res[i] = answer;
    }

    for (ll x : res) {
        cout << x << " ";
    }
    cout << "\n";
}