#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    vector<pair<ll, int>> votes_and_index(n);
    for (int i = 0; i < n; ++i) votes_and_index[i] = {A[i], i};

    sort(votes_and_index.rbegin(), votes_and_index.rend());

    vector<ll> required_votes(n, 0);
    vector<ll> remaining_votes = k;
    for (int i = 0; i < n; ++i) {
        if (i >= m) {
            // Calculate the required votes to ensure this candidate's votes are greater than the top m-1 candidates
            required_votes[i] = votes_and_index[i - m].first + 1;
        }
        remaining_votes -= votes_and_index[i].first;
        votes_and_index[i].first -= votes_and_index[i].first;  // Subtract the votes already obtained
    }

    vector<ll> results(n);
    for (int i = 0; i < n; ++i) {
        if (i < m) {
            // These candidates are guaranteed to win with the votes they have
            results[i] = 0;
        } else {
            // Calculate minimum additional votes needed to guarantee victory
            auto it = upper_bound(votes_and_index.rbegin(), votes_and_index.rend(), {0, 0}) - votes_and_index.rbegin();
            ll votes_needed = required_votes[i] - votes_and_index[i].first;
            if (votes_needed <= remaining_votes) {
                results[i] = votes_needed;
            } else {
                results[i] = -1; // Not enough remaining votes to guarantee victory
            }
        }
    }

    for (ll result : results) cout << result << " ";
    cout << endl;
    return 0;
}