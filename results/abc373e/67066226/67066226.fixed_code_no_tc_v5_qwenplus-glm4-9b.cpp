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
    vector<ll> A(n);
    ll total_votes = 0;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        total_votes += A[i];
    }

    // Sorting candidates by their current votes
    vector<pair<ll, int>> sorted_candidates(n);
    for (int i = 0; i < n; ++i) {
        sorted_candidates[i] = {A[i], i};
    }
    sort(sorted_candidates.begin(), sorted_candidates.end());

    // Array to store the minimum additional votes needed for each candidate
    vector<ll> min_votes_needed(n, 0);

    // We need to consider candidates from the end if we want to win with M candidates
    for (int i = n - 1; i >= n - m; --i) {
        // Calculate the votes needed to ensure victory for sorted_candidates[i]
        ll votes_needed = max(0LL, m * (sorted_candidates[i].first + 1) - (n - m) * sorted_candidates[i].first - total_votes);
        min_votes_needed[sorted_candidates[i].second] = votes_needed;
        total_votes += votes_needed; // Update total votes after assigning them to this candidate
    }

    // Update the answers for the remaining candidates
    for (int i = n - m - 1; i >= 0; --i) {
        min_votes_needed[sorted_candidates[i].second] = max(min_votes_needed[sorted_candidates[i].second], min_votes_needed[i + 1]);
    }

    // Output the results
    for (int i = 0; i < n; ++i) {
        if (min_votes_needed[i] == LLONG_MAX) {
            cout << "-1 ";
        } else {
            cout << min_votes_needed[i] << " ";
        }
    }
    cout << '\n';
    return 0;
}