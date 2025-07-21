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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort indices based on vote counts in descending order
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] > a[j]; });

    // Calculate prefix sums of sorted vote counts
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = a[ord[i]] + pref[i];
    }

    // Initialize answer array
    vector<ll> ans(n, -1);

    // Iterate over each candidate
    for (int i = 0; i < n; ++i) {
        ll x = 0;
        ll needed_votes = 0;

        // Calculate the maximum number of votes needed to ensure victory
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                needed_votes = max(needed_votes, a[ord[j]]);
            }
        }

        // Ensure we can surpass the maximum needed votes by at least one more vote
        needed_votes++;

        // Binary search for the minimum additional votes required
        ll l = 0, r = k;
        while (l <= r) {
            ll mid = (l + r) / 2;
            ll total_votes = pref[i + 1] + mid;
            ll votes_needed_by_others = needed_votes * (n - i - 1);

            if (total_votes >= votes_needed_by_others) {
                ans[ord[i]] = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }

    // Output the results
    for (auto i : ans) cout << i << ' ';
    return 0;
}