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

    // Create a list of pairs (index, votes)
    vector<pair<int, ll>> candidates;
    for (int i = 0; i < n; ++i) {
        candidates.emplace_back(i, a[i]);
    }

    // Sort candidates by their vote counts in ascending order
    sort(candidates.begin(), candidates.end(), [](const pair<int, ll>& p1, const pair<int, ll>& p2) {
        return p1.second < p2.second;
    });

    // Calculate the prefix sums of votes
    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + candidates[i - 1].second;
    }

    // Initialize the answer array
    vector<ll> ans(n, -1);

    // Process each candidate
    for (int i = 0; i < n; ++i) {
        ll target_votes = pref[n] - pref[i] + candidates[i].second;
        ll remaining_votes = k - (pref[n] - pref[i]);

        // Binary search to find the minimum additional votes needed
        ll left = 0, right = remaining_votes + 1;
        while (left < right) {
            ll mid = (left + right) / 2;
            ll total_votes_if_win = candidates[i].second + mid;
            ll count_greater = n - (upper_bound(candidates.begin(), candidates.end(), make_pair(-1, total_votes_if_win)) - candidates.begin());

            if (count_greater < m) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        if (left <= remaining_votes) {
            ans[candidates[i].first] = left;
        }
    }

    // Output the results
    for (ll x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}