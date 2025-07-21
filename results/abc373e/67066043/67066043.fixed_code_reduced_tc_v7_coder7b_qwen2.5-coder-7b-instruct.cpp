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

    // Sort candidates by the number of votes they have received
    vector<pair<ll, int>> candidates(n);
    for (int i = 0; i < n; ++i) {
        candidates[i] = {a[i], i};
    }
    sort(candidates.begin(), candidates.end());

    // Calculate prefix sums of sorted votes
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + candidates[i].first;
    }

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        ll target = candidates[i].first;
        ll remaining_votes = k - pref[n];

        // Binary search for the minimum additional votes needed
        ll l = 0, r = remaining_votes;
        while (l <= r) {
            ll mid = (l + r) / 2;
            int pos = upper_bound(candidates.begin(), candidates.end(), pair<ll, int>{target + mid + 1, 0}) - candidates.begin();

            // Check if the candidate can still win with mid additional votes
            if (pos - i - 1 < m) {
                ans[candidates[i].second] = mid;
                break;
            } else {
                l = mid + 1;
            }
        }
    }

    for (ll x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}