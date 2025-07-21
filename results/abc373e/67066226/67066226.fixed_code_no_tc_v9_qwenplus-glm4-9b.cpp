#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    ll total_votes = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_votes += a[i];
    }

    // Sort candidates by votes received in descending order
    vector<pair<ll, int>> candidates(n);
    for (int i = 0; i < n; ++i) {
        candidates[i] = {a[i], i};
    }
    sort(candidates.rbegin(), candidates.rend());

    vector<ll> remaining_votes(k - total_votes);
    for (int i = 0; i < k - total_votes; ++i) {
        cin >> remaining_votes[i];
    }
    sort(remaining_votes.rbegin(), remaining_votes.rend());

    vector<ll> ans(n, -1);

    // Calculate the minimum votes needed for each candidate to guarantee victory
    for (int i = 0; i < m; ++i) {
        ll current_votes = candidates[i].first;
        ll required_votes = candidates[i].first + remaining_votes[i];
        if (required_votes >= m) {
            // If the candidate already has the required votes, no need for additional votes
            ans[candidates[i].second] = 0;
        } else {
            // Calculate the votes needed to surpass the other candidates
            ll max_votes = 0;
            for (int j = i + 1; j < n; ++j) {
                max_votes = max(max_votes, candidates[j].first + remaining_votes[j]);
            }
            ans[candidates[i].second] = max_votes - current_votes - 1;
        }
    }

    // Output the result for each candidate
    for (ll vote : ans) {
        cout << vote << ' ';
    }
    cout << '\n';

    return 0;
}