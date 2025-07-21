#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Candidate {
    int index;
    long long votes;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n);
    long long total_votes = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_votes += a[i];
    }

    // Create a vector of candidates with their votes and indices
    vector<Candidate> candidates(n);
    for (int i = 0; i < n; ++i) {
        candidates[i].index = i;
        candidates[i].votes = a[i];
    }

    // Sort candidates by votes in descending order
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
    });

    // Create a prefix sum array of the sorted votes
    vector<long long> prefix(n);
    prefix[0] = candidates[0].votes;
    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] + candidates[i].votes;
    }

    // Calculate the minimum votes needed for the m-th candidate to guarantee victory
    long long required_votes = prefix[m - 1] + m * candidates[m - 1].votes;

    // Vector to store the result
    vector<long long> result(n);
    for (int i = 0; i < n; ++i) {
        // If the current candidate has already reached more than or equal to required_votes, they are guaranteed to win
        if (candidates[i].votes >= required_votes) {
            result[candidates[i].index] = 0;
        } else {
            // Calculate the minimum additional votes needed for the candidate to guarantee victory
            long long additional_votes = required_votes - candidates[i].votes;
            if (additional_votes <= k - total_votes) {
                result[candidates[i].index] = additional_votes;
            } else {
                // Candidate cannot guarantee victory even if all remaining votes go to them
                result[candidates[i].index] = -1;
            }
        }
    }

    // Output the result
    for (const auto& res : result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}