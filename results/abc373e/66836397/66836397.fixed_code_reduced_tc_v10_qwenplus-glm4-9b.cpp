#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

using ll = long long;

ll ceil_div(ll a, ll b) {
    return (a + b - 1) / b;
}

int main() {
    ll n, m, K;
    cin >> n >> m >> K;

    vector<ll> a(n);
    ll sum_votes = 0;
    for (ll &ai : a) {
        cin >> ai;
        sum_votes += ai;
    }

    ll remaining_votes = K - sum_votes;

    vector<pair<ll, ll>> candidates(n);
    for (ll i = 0; i < n; ++i) {
        candidates[i] = {a[i], -i}; // Store votes and negative index for sorting DESC by votes
    }
    sort(candidates.begin(), candidates.end());

    vector<ll> result(n, -1);
    ll max_other_votes = 0;
    for (ll i = 0; i < n; ++i) {
        ll votes_needed = m - 1; // To win, need at least m-1 more than the current max
        ll current_votes = candidates[i].first;
        if (votes_needed <= remaining_votes) {
            result[-candidates[i].second] = votes_needed - current_votes;
        } else {
            // Check if this candidate can win with remaining votes
            ll max_index = upper_bound(candidates.begin(), candidates.end(), {current_votes + remaining_votes, 0}) - candidates.begin();
            max_other_votes = max(max_other_votes, candidates[max_index - 1].first);
            if (current_votes + remaining_votes > max_other_votes) {
                result[-candidates[i].second] = remaining_votes - (current_votes - max_other_votes);
            }
        }
    }

    for (ll res : result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}