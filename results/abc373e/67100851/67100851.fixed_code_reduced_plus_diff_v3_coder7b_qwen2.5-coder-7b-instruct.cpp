#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(vector<Candidate>& candidates, vector<long long>& prefixSum, int i, long long additionalVotes) {
    int M = candidates.size();
    long long totalVotes = prefixSum.back() + additionalVotes;
    
    // Calculate the votes needed for candidate i to win
    long long requiredVotes = totalVotes / (M - 1);
    
    // Check if candidate i can win after receiving additionalVotes
    for (int j = 0; j < i; ++j) {
        if (candidates[j].votes > requiredVotes) {
            return false;
        }
    }
    
    return true;
}

void solve(vector<long long>& votes, int N, int M, long long K) {
    vector<Candidate> candidates;
    vector<long long> prefixSum(N + 1, 0);

    // Initialize candidates and prefix sum array
    for (int i = 0; i < N; ++i) {
        candidates.push_back({votes[i], i});
        prefixSum[i + 1] = prefixSum[i] + votes[i];
    }

    // Sort candidates based on votes in descending order
    sort(candidates.begin(), candidates.end(), [&](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
    });

    vector<long long> results(N, 0);

    // Determine the minimum additional votes needed for each candidate
    for (int i = 0; i < N; ++i) {
        long long leftOver = K - prefixSum[i];
        
        // Binary search for the minimum additional votes needed
        int low = 0, high = leftOver;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (canWin(candidates, prefixSum, i, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        results[candidates[i].index] = low;
    }

    // Output the results
    for (int i = 0; i < N; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;
}

int main() {
    int N, M;
    long long K;
    cin >> N >> M >> K;

    vector<long long> votes(N);
    for (int i = 0; i < N; ++i) {
        cin >> votes[i];
    }

    solve(votes, N, M, K);
    return 0;
}