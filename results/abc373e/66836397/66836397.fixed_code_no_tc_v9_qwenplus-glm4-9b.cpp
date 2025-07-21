#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

using ll = long long;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<ll> remaining_votes(k - accumulate(a.begin(), a.end(), 0LL));
    iota(remaining_votes.begin(), remaining_votes.end(), 0);

    vector<ll> result(n, -1); // Initialize result with -1 (indicating no possible victory)
    for (int i = 0; i < n; ++i) {
        ll votes_needed = numeric_limits<ll>::max();
        int remaining_candidates = n - i;

        for (int j = 0; j < m && j < n - i; ++j) {
            ll possible_votes = a[i + j] + remaining_votes[j] - a[i];
            if (possible_votes >= a[i]) { // Ensure candidate i can win against the top m candidates
                votes_needed = min(votes_needed, possible_votes - a[i]);
            } else {
                votes_needed = -1; // Candidate i cannot win even with all remaining votes
                break;
            }
        }

        result[i] = votes_needed == numeric_limits<ll>::max() ? 0 : votes_needed;
    }

    cout << (result.front() == -1 ? "IMPOSSIBLE" : to_string(result.front()));
    for (int i = 1; i < n; ++i) {
        cout << " " << (result[i] == -1 ? "IMPOSSIBLE" : to_string(result[i]));
    }
    cout << endl;

    return 0;
}