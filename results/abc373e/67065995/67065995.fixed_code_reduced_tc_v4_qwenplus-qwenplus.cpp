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

    // Total remaining votes
    ll total_remaining = k;
    for (ll ai : a) total_remaining -= ai;

    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    vector<ll> sorted_a = a;
    sort(all(sorted_a));

    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + sorted_a[i];
    }

    vector<ll> ans(n, -1);

    for (int idx = 0; idx < n; idx++) {
        int i = ord[idx];
        ll current = a[i];

        ll low = 0, high = total_remaining;
        ll res = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll needed = 0;

            // We want to ensure that at most M-1 candidates have strictly more votes than this candidate after adding X votes

            // Binary search to find how many candidates have votes > current + mid
            // Find first index where a[j] > current + mid
            int pos = upper_bound(all(sorted_a), current + mid) - sorted_a.begin();

            if (pos >= n - (m - 1)) {
                // This candidate is already in top M even if others get max possible
                res = 0;
                break;
            }

            // Need to raise the lowest (M-1) candidates with fewer votes above current+mid
            // Take the last (M-1) candidates below current+mid
            int from = max(0, n - m + 1);
            ll threshold = current + mid + 1;

            ll sum_needed = threshold * (n - from) - (prefix[n] - prefix[from]);
            if (sum_needed <= total_remaining - mid) {
                // Can afford to make sure only M-1 candidates are above us
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        ans[i] = (res == -1 ? -1 : res);
    }

    for (auto x : ans) {
        cout << (x == -1 ? -1 : max<ll>(0, x)) << ' ';
    }
}