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

    // Sort indices based on the number of votes
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });

    // Calculate prefix sums for sorted vote counts
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[ord[i]];
    }

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        ll needed_votes = 0;
        if (i < n - m) {
            needed_votes = (n - m - i) * (a[ord[i]] + 1) - (pref[n] - pref[i + 1]);
        } else {
            needed_votes = k - (pref[n] - pref[i]);
        }

        // Ensure the candidate can still win even if other candidates get the maximum possible votes
        if (needed_votes >= 0 && needed_votes <= k) {
            ans[ord[i]] = needed_votes;
        }
    }

    for (auto i : ans) cout << i << ' ';
    return 0;
}