#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort indices based on the number of votes in ascending order
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return a[i] < a[j]; });

    // Calculate the prefix sum of sorted votes
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[idx[i]];
    }

    vector<ll> ans(n, -1);

    for (int i = 0; i < n; ++i) {
        int rank = i;
        ll needed_votes = 0;

        // Calculate the number of candidates that can surpass this candidate
        for (int j = rank + 1; j < min(rank + m, n); ++j) {
            needed_votes += max(0LL, a[idx[j]] - a[idx[rank]] + 1);
        }

        // Check if we can cover the needed votes with remaining votes
        if (k >= needed_votes) {
            ans[idx[rank]] = 0;
        } else {
            // Binary search for the minimum number of votes needed
            ll lo = 0, hi = k;
            while (lo < hi) {
                ll mid = (lo + hi) / 2;
                ll current_needed = needed_votes - mid * (n - rank - 1);
                if (current_needed <= k) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            ans[idx[rank]] = lo;
        }
    }

    for (ll v : ans) {
        cout << v << " ";
    }

    return 0;
}