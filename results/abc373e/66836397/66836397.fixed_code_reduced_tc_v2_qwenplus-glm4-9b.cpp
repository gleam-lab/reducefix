#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <cmath>

using namespace std;

int main() {
    long long n, m, K;
    cin >> n >> m >> K;
    vector<long long> votes(n);
    long long total_votes = 0;

    for (long long &vote : votes) {
        cin >> vote;
        total_votes += vote;
    }

    // Sort votes to find the current highest and second highest easily
    sort(votes.begin(), votes.end(), greater<long long>());

    vector<long long> additional_votes(n);
    for (long long i = 0; i < n; ++i) {
        // Calculate the votes needed to guarantee victory
        long long votes_needed = votes[m - 1] - votes[i] + 1;

        // If the candidate is already among the top M, no need for additional votes
        if (i < m) {
            additional_votes[i] = max(0LL, votes_needed);
        } else {
            // If candidate i is not among the top M, we need to consider the remaining votes
            long long remaining_votes = K - total_votes;
            // If the remaining votes are not enough to make candidate i the top M
            if (remaining_votes < votes_needed - (m - i - 1)) {
                additional_votes[i] = -1;
            } else {
                // Calculate the minimum votes needed to become top M from i to m-1
                long long votes_to_top = votes[0] + (m - 1) * votes_needed / (m - i);
                additional_votes[i] = votes_to_top - votes[i] - (m - i - 1);
            }
        }

        // If additional_votes[i] is -1, the candidate cannot secure victory
        if (additional_votes[i] == -1) {
            cout << additional_votes[i] << " ";
        } else {
            // Otherwise, print the minimum additional votes needed
            cout << max(0LL, additional_votes[i]) << " ";
        }
    }

    cout << endl;
    return 0;
}