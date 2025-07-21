#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(vector<Candidate>& candidates, int M, long long totalVotesNeeded, int targetIndex) {
    int n = candidates.size();
    vector<long long> prefixSum(n + 1, 0);

    // Calculate prefix sums
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + candidates[i - 1].votes;
    }

    // Sort candidates based on votes in descending order
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
    });

    // Check if we can win with the given votes needed
    for (int i = 0; i < n; ++i) {
        int rank = i + 1;
        if (rank <= M) continue;

        long long requiredVotes = prefixSum[n] - prefixSum[rank - 1] + 1;
        if (requiredVotes > totalVotesNeeded) {
            return false;
        }
    }

    return true;
}

int main() {
    int N, M;
    long long K;
    cin >> N >> M >> K;

    vector<Candidate> candidates(N);
    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
    }

    // Calculate the total votes already counted
    long long totalVotesCounted = 0;
    for (auto& candidate : candidates) {
        totalVotesCounted += candidate.votes;
    }

    // Remaining votes to be counted
    long long remainingVotes = K - totalVotesCounted;

    // Calculate the minimum votes needed for each candidate to win
    vector<long long> minVotesNeeded(N, -1);

    for (int i = 0; i < N; ++i) {
        if (canWin(candidates, M, remainingVotes, i)) {
            minVotesNeeded[i] = 0;
        } else {
            long long lo = 0, hi = remainingVotes;
            while (hi - lo > 1) {
                long long mid = lo + (hi - lo) / 2;
                if (canWin(candidates, M, remainingVotes - mid, i)) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            if (canWin(candidates, M, remainingVotes - lo, i)) {
                minVotesNeeded[i] = lo;
            } else if (canWin(candidates, M, remainingVotes - hi, i)) {
                minVotesNeeded[i] = hi;
            }
        }
    }

    // Sort results by original indices
    sort(minVotesNeeded.begin(), minVotesNeeded.end());

    // Print results
    for (int i = 0; i < N; ++i) {
        cout << minVotesNeeded[i] << " ";
    }
    cout << endl;

    return 0;
}