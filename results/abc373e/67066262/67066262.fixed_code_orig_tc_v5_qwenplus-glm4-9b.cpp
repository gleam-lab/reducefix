#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> votes(n);
    
    // Read and subtract the votes that have already been counted.
    for (int i = 0; i < n; i++) {
        cin >> votes[i];
        k -= votes[i];
    }

    // Sort the candidates based on their votes in descending order.
    sort(votes.rbegin(), votes.rend());

    vector<ll> additional_votes(n);

    // Calculate the minimum additional votes needed for each candidate
    for (int i = 0; i < n; i++) {
        // Calculate the number of votes we need to take from the remaining candidates
        // to ensure this candidate wins.
        if (i < m - 1) {
            additional_votes[i] = votes[i + 1] - votes[i];
        } else {
            // If the remaining votes are not enough for the first m-1 candidates to
            // surpass this candidate's current vote count, then this candidate can
            // win even with the maximum votes from the remaining ballots.
            additional_votes[i] = k - votes[i] + votes[0];
        }
    }

    // Output the results
    for (int i = 0; i < n; i++) {
        if (additional_votes[i] <= k) {
            cout << additional_votes[i] << ' ';
        } else {
            cout << -1 << ' '; // Cannot guarantee victory, even with all remaining votes.
        }
    }

    return 0;
}