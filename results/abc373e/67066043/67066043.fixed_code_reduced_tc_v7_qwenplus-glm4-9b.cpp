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
    ll total_votes = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_votes += a[i];
    }
    vector<pair<ll, int>> sorted_candidates(n);
    for (int i = 0; i < n; ++i) {
        sorted_candidates[i] = {a[i], i};
    }
    sort(sorted_candidates.begin(), sorted_candidates.end());
    vector<ll> prefix(n);
    prefix[0] = sorted_candidates[0].first;
    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] + sorted_candidates[i].first;
    }
    vector<ll> required_votes(n);
    for (int i = 0; i < n; ++i) {
        ll max_rival_votes = (i < m - 1) ? prefix[i + m - 1] : prefix[n - 1];
        ll votes_needed = max_rival_votes - sorted_candidates[i].first + 1;
        required_votes[sorted_candidates[i].second] = votes_needed;
    }
    vector<ll> remaining_votes(k - total_votes, 1);
    sort(required_votes.begin(), required_votes.end());
    for (ll i : required_votes) {
        auto it = upper_bound(remaining_votes.begin(), remaining_votes.end(), i);
        if (it != remaining_votes.end()) {
            *it = i;
        } else {
            cout << -1 << " ";
            continue;
        }
    }
    cout << '\n';
    return 0;
}