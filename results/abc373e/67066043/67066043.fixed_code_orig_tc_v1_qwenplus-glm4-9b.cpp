#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool compare(const Candidate &a, const Candidate &b) {
    return a.votes > b.votes;
}

int main() {
    int n, m, k;
    vector<long long> votes;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        long long vote;
        cin >> vote;
        votes.push_back(vote);
    }

    vector<Candidate> candidates(n);
    for (int i = 0; i < n; ++i) {
        candidates[i] = {votes[i], i};
    }

    // Sort candidates by votes descending
    sort(candidates.begin(), candidates.end(), compare);

    // Calculate prefix sums
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + candidates[i - 1].votes;
    }

    // Determine the minimum additional votes each candidate needs
    vector<long long> additionalVotesNeeded(n, -1);
    for (int i = 0; i < n; ++i) {
        long long currentVotes = candidates[i].votes;
        long long requiredVotes = prefixSum[candidates[i].index + m] - prefixSum[candidates[i].index + 1];
        long long additionalVotes = max(0LL, requiredVotes - currentVotes);
        if (additionalVotes <= k) {
            additionalVotesNeeded[candidates[i].index] = additionalVotes;
        } else {
            additionalVotesNeeded[candidates[i].index] = -1;
        }
    }

    // Output the results
    for (int i = 0; i < n; ++i) {
        cout << additionalVotesNeeded[i] << " ";
    }
    cout << endl;

    return 0;
}