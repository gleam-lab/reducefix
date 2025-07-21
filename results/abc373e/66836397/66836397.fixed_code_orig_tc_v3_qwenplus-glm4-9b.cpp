#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> votes(n);
    long long sum_votes = 0;
    for (int i = 0; i < n; ++i) {
        cin >> votes[i];
        sum_votes += votes[i];
    }

    // Calculate remaining votes after the current count
    long long remaining_votes = k - sum_votes;

    // Sort votes to find out the minimum votes needed to win
    sort(votes.begin(), votes.end());

    // For each candidate, calculate the minimum additional votes needed to guarantee victory
    for (int i = 0; i < n; ++i) {
        // Calculate the number of candidates that have more votes than current candidate
        int candidates_with_more_votes = n - lower_bound(votes.begin(), votes.end(), votes[i]) - 1;
        
        if (candidates_with_more_votes < m) {
            // If the number of candidates with more votes is less than m, no additional votes are needed
            cout << 0 << " ";
        } else {
            // Otherwise, calculate the minimum additional votes needed
            long long additional_votes_needed = m - candidates_with_more_votes - 1;
            // Ensure that the additional votes do not exceed the remaining votes
            if (additional_votes_needed > remaining_votes) {
                cout << -1 << " ";
            } else {
                cout << additional_votes_needed << " ";
            }
        }
    }
    cout << endl;
    return 0;
}