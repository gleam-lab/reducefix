#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> votes(n);
    long long total_votes = 0;
    for (int i = 0; i < n; ++i) {
        cin >> votes[i];
        total_votes += votes[i];
    }
    sort(votes.begin(), votes.end(), greater<long long>()); // Sort in descending order

    vector<long long> required_votes(n, -1); // Initialize the required votes to -1

    for (int i = 0; i < n; ++i) {
        // The M-th highest candidate's votes
        long long mth_highest_votes = (i < m - 1) ? votes[m - 1] : votes[m - 2];
        // Remaining votes to be counted
        long long remaining_votes = k - total_votes;
        // Votes needed to guarantee victory
        long long votes_needed = max(0LL, mth_highest_votes - votes[i] + remaining_votes);
        required_votes[i] = votes_needed;
        total_votes += votes_needed; // Update total votes
    }

    for (int i = 0; i < n; ++i) {
        if (required_votes[i] == -1) {
            cout << -1 << " ";
        } else {
            cout << required_votes[i] << " ";
        }
    }
    cout << endl;

    return 0;
}