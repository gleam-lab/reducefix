#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(const vector<Candidate>& candidates, int i, long long additionalVotes, int M, long long totalRemainingVotes) {
    // Calculate the number of candidates who will have more votes than candidate i
    long long count = 0;
    for (const auto& c : candidates) {
        if (c.votes + additionalVotes > candidates[i].votes) {
            ++count;
        }
    }
    
    // Check if count is less than M
    return count < M;
}

void binarySearch(vector<Candidate>& candidates, int i, long long totalRemainingVotes, int M, long long& result) {
    long long low = 0, high = totalRemainingVotes;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (canWin(candidates, i, mid, M, totalRemainingVotes)) {
            result = min(result, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
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
    
    // Sort candidates based on votes in descending order
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
    });
    
    // Calculate the prefix sum array
    vector<long long> prefixSum(N + 1);
    for (int i = 1; i <= N; ++i) {
        prefixSum[i] = prefixSum[i - 1] + candidates[i - 1].votes;
    }
    
    // Total remaining votes after counting known votes
    long long totalRemainingVotes = K - prefixSum.back();
    
    // Initialize results array
    vector<long long> results(N, -1);
    
    // For each candidate, perform binary search to find the minimum additional votes needed
    for (int i = 0; i < N; ++i) {
        binarySearch(candidates, i, totalRemainingVotes, M, results[candidates[i].index]);
    }
    
    // Print the results
    for (int i = 0; i < N; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;
    
    return 0;
}