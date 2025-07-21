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
    k -= total_votes;

    // Sort candidates based on votes and index to maintain original order
    vector<pair<ll, int>> sorted_a(n);
    for (int i = 0; i < n; ++i) {
        sorted_a[i] = {a[i], i};
    }
    sort(sorted_a.begin(), sorted_a.end());

    vector<ll> prefix_sum(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + sorted_a[i - 1].first;
    }

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        if (i < m - 1) {
            // If there are at least m-1 candidates with more votes, they will secure the win
            ans[sorted_a[i].second] = 0;
        } else {
            // Candidate at position m-1 needs to consider the remaining candidates
            ll votes_needed = m - 1;
            ll max_votes_by_others = prefix_sum[n] - prefix_sum[n - m + 1];
            votes_needed -= max_votes_by_others - sorted_a[i].first;

            if (votes_needed <= k) {
                ans[sorted_a[i].second] = votes_needed;
            } else {
                ans[sorted_a[i].second] = -1;
            }
        }
    }

    for (ll vote : ans) {
        cout << vote << ' ';
    }

    return 0;
}