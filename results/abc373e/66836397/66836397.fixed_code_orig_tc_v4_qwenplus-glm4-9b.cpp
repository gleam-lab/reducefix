#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n, m, K;
    cin >> n >> m >> K;

    vector<pair<ll, int>> candidates(n);
    for (int i = 0; i < n; ++i) {
        cin >> candidates[i].first; // votes received
        candidates[i].second = i + 1; // candidate number
    }

    // Sort candidates by votes descending
    sort(candidates.begin(), candidates.end(), [](const pair<ll, int>& a, const pair<ll, int>& b) {
        return a.first > b.first;
    });

    vector<ll> additional_votes(n, -1);
    ll remaining_votes = K - candidates[0].first;

    // Calculate the minimum votes needed for each candidate to guarantee victory
    for (int i = 0; i < n; ++i) {
        if (i >= m) {
            ll votes_needed = candidates[i].first + remaining_votes - candidates[i - m].first;
            if (votes_needed >= candidates[i].first) {
                additional_votes[candidates[i].second - 1] = 0;
            } else {
                additional_votes[candidates[i].second - 1] = votes_needed - candidates[i].first;
            }
        }
    }

    // Output the result
    for (int i = 0; i < n; ++i) {
        if (additional_votes[i] != -1) {
            cout << additional_votes[i] << ' ';
        } else {
            cout << -1 << ' ';
        }
    }
    cout << '\n';

    return 0;
}