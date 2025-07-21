#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    long long votes;
    int idx;
} Candidate;

bool canWin(const vector<Candidate>& candidates, long long votes, int candidate_index, int M) {
    long long sum = 0;
    for (int i = 0; i < candidates.size(); ++i) {
        if (i != candidate_index) {
            if (candidates[i].votes + votes >= candidates[candidate_index].votes) {
                sum++;
            }
        }
    }
    return sum < M;
}

int main() {
    int N, M;
    long long K;
    cin >> N >> M >> K;
    
    vector<Candidate> candidates(N);
    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].idx = i;
    }

    // Sort by votes in descending order
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
    });

    // Calculate prefix sums
    vector<long long> prefixSum(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        prefixSum[i] = prefixSum[i - 1] + candidates[i - 1].votes;
    }

    long long remainingVotes = K - prefixSum[N];

    // Check each candidate to see if they can win
    for (int i = 0; i < N; ++i) {
        long long votes_needed = 0;
        if (canWin(candidates, votes_needed, i, M)) {
            votes_needed = candidates[i].votes - prefixSum[i] + M - 1;
            if (votes_needed > remainingVotes) {
                votes_needed = remainingVotes;
            }
            if (canWin(candidates, votes_needed, i, M)) {
                cout << votes_needed << " ";
            } else {
                cout << "-1 ";
            }
        } else {
            cout << "-1 ";
        }
    }

    cout << endl;
    return 0;
}