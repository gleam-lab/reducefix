#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Calculate the prefix sum of sorted votes
    vector<ll> sorted_a(a);
    sort(sorted_a.begin(), sorted_a.end());
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = sorted_a[i] + pref[i];
    }

    // Determine the minimum additional votes needed for each candidate
    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        ll target_votes = a[i] + 1;
        int rank = upper_bound(sorted_a.begin(), sorted_a.end(), target_votes - 1) - sorted_a.begin();

        // If the current candidate's rank is greater than or equal to M, they are already elected
        if (rank >= m) {
            ans[i] = 0;
            continue;
        }

        // Calculate the maximum votes the highest ranked candidate can get without losing
        ll max_votes_higher_ranks = pref[n] - pref[rank];

        // Calculate the minimum additional votes needed
        if (max_votes_higher_ranks > k) {
            ans[i] = -1;
        } else {
            ans[i] = max(0LL, target_votes - a[i] - (k - max_votes_higher_ranks));
        }
    }

    // Output the results
    for (ll x : ans) {
        cout << x << " ";
    }
    return 0;
}