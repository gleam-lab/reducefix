#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort candidates based on the votes they have received
    sort(a.begin(), a.end(), greater<long long>());

    vector<long long> ans(n, -1); // Initialize answers with -1

    // Calculate additional votes needed for each candidate
    for (int i = 0; i < n; ++i) {
        long long current_votes = a[i];
        long long votes_needed_to_win = current_votes;
        long long other_votes = 0;

        // Calculate votes of the top M candidates
        for (int j = 0; j < m && j < n; ++j) {
            if (j != i) {
                other_votes += a[j];
            }
        }

        // Check if this candidate can possibly win
        if (other_votes + current_votes <= k) {
            votes_needed_to_win = max(0LL, current_votes - other_votes - 1); // They need one more vote than the current minimum to win
        }

        // Check if the candidate can win with the remaining votes
        if (votes_needed_to_win <= k - current_votes) {
            ans[i] = votes_needed_to_win;
        } else {
            ans[i] = -1; // Cannot win even with all remaining votes
        }
    }

    // Output the results
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}