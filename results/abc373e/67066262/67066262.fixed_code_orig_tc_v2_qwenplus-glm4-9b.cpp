#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1e18;

struct Candidate {
    long long votes;
    int index;
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Step 1: Calculate remaining votes
    long long remaining_votes = k - accumulate(A.begin(), A.end(), 0LL);

    // Step 2: Sort candidates by votes in descending order
    vector<Candidate> candidates(n);
    for (int i = 0; i < n; ++i) {
        candidates[i] = {A[i], i};
    }
    sort(candidates.begin(), candidates.end(), [](const Candidate &a, const Candidate &b) {
        return a.votes > b.votes;
    });

    // Step 3: Determine the minimum votes required for each candidate
    vector<long long> required_votes(n);
    for (int i = 0; i < n; ++i) {
        // Check if the next candidate is within the top M candidates
        int next_candidate_index = lower_bound(candidates.begin() + i + 1, candidates.end(),
                                              Candidate{A[i] - 1, 0}, [](const Candidate &a, const Candidate &b) {
                                                  return a.votes > b.votes;
                                              }) - candidates.begin();

        // If the next candidate is within the top M candidates, calculate the votes required to reach them
        if (next_candidate_index - i <= m) {
            long long votes_needed = (A[i] - 1) - candidates[next_candidate_index].votes;
            required_votes[candidates[i].index] = votes_needed;
        } else {
            // If not, check if we can reach any candidate with less than M votes ahead
            int j = i;
            while (j + 1 < n && candidates[j + 1].votes > A[i] - 1) {
                ++j;
            }
            if (j + 1 < n) {
                required_votes[candidates[i].index] = (A[i] - 1) - candidates[j + 1].votes;
            } else {
                // If we cannot reach any candidate, it's impossible to guarantee victory for this candidate
                required_votes[candidates[i].index] = INF;
            }
        }
    }

    // Step 4: Output the minimum votes required for each candidate
    for (const auto &vote : required_votes) {
        if (vote == INF) {
            cout << -1 << ' ';
        } else {
            cout << vote << ' ';
        }
    }
    cout << '\n';

    return 0;
}