#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(vector<Candidate>& candidates, int i, long long x) {
    // Sort candidates by votes in descending order
    sort(candidates.begin(), candidates.end(), [&](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
    });

    int needed = x + 1;
    int remainingCandidates = candidates.size() - 1;

    // Check if candidate i can win after receiving x additional votes
    for (int j = 0; j < remainingCandidates; ++j) {
        if (candidates[j].votes >= candidates[i].votes + needed) {
            return false;
        }
    }

    return true;
}

vector<long long> minVotesRequired(vector<long long>& votes, int M, long long totalVotes) {
    int n = votes.size();
    vector<Candidate> candidates(n);

    // Initialize candidate structure
    for (int i = 0; i < n; ++i) {
        candidates[i] = {votes[i], i};
    }

    vector<long long> result(n, -1); // Initialize results as -1 (impossible)

    // Binary search for minimum votes required for each candidate
    for (int i = 0; i < n; ++i) {
        long long low = 0, high = totalVotes - votes[i];

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canWin(candidates, i, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // Check if low is valid
        if (low <= totalVotes - votes[i]) {
            result[i] = low;
        }
    }

    return result;
}

int main() {
    int N, M;
    long long K;
    cin >> N >> M >> K;

    vector<long long> votes(N);
    for (int i = 0; i < N; ++i) {
        cin >> votes[i];
    }

    long long remainingVotes = K - accumulate(votes.begin(), votes.end(), 0LL);

    vector<long long> result = minVotesRequired(votes, M, remainingVotes);

    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}