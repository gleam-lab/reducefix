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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort indices based on vote count
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] > a[j]; });

    // Calculate prefix sums for quick range sum queries
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = a[i] + pref[i];
    }

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; i++) {
        // Calculate the maximum number of votes needed for candidate i to stay in the top M positions
        ll max_votes_needed = 0;
        for (int j = 0; j < min(i + 1, m); j++) {
            max_votes_needed = max(max_votes_needed, a[ord[j]]);
        }

        // If candidate i is already in the top M positions, no additional votes are needed
        if (a[ord[i]] > max_votes_needed) {
            ans[ord[i]] = 0;
        } else {
            // Calculate the minimum number of additional votes needed
            ll remaining_votes = k;
            ll additional_votes = max_votes_needed - a[ord[i]];
            if (additional_votes <= remaining_votes) {
                ans[ord[i]] = additional_votes;
            }
        }
    }

    for (auto i : ans) cout << i << ' ';
    return 0;
}