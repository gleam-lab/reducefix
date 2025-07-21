#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> votes(n);
    for (int i = 0; i < n; ++i) {
        cin >> votes[i];
    }

    // Sort the votes to determine the order
    sort(votes.begin(), votes.end());

    vector<long long> additional_votes(n);
    for (int i = 0; i < n; ++i) {
        // Remaining votes to be distributed
        long long remaining_votes = k - accumulate(votes.begin(), votes.begin() + n, 0LL);

        // The top candidate has votes[n-1]
        if (votes[n - 1] - votes[i] < m) {
            // If the current candidate is very close to the top candidate
            additional_votes[i] = min(remaining_votes, votes[n - 1] - votes[i]) - votes[i];
        } else {
            // If the current candidate is very far from the top candidate
            additional_votes[i] = min(remaining_votes, votes[n - 1] - votes[i] - 1) - votes[i];
        }
    }

    // Print the result for each candidate
    for (int i = 0; i < n; ++i) {
        if (additional_votes[i] < 0) {
            cout << "-1 ";
        } else {
            cout << additional_votes[i] << " ";
        }
    }

    return 0;
}