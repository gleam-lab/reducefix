#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(vector<Candidate>& candidates, long long additionalVotes, int m, long long remainingVotes) {
    int n = candidates.size();
    vector<long long> prefixSum(n + 1, 0);
    
    // Calculate prefix sum of votes including additional votes
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + candidates[i].votes + additionalVotes;
    }
    
    // Count how many candidates have more votes than the current candidate
    int countMoreVotes = 0;
    for (int i = 0; i < n; ++i) {
        long long totalVotes = prefixSum[n] - prefixSum[i + 1];
        long long remainingVotesForOtherCandidates = remainingVotes - (prefixSum[n] - prefixSum[i]);
        
        if (totalVotes > remainingVotesForOtherCandidates) {
            ++countMoreVotes;
        }
    }
    
    // Check if the count is within the allowed limit
    return countMoreVotes < m;
}

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;
    
    vector<Candidate> candidates(n);
    for (int i = 0; i < n; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
    }
    
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes < b.votes;
    });
    
    vector<long long> result(n, LLONG_MAX);
    
    for (int i = 0; i < n; ++i) {
        if (canWin(candidates, 0, m, k)) {
            result[i] = 0;
            continue;
        }
        
        long long low = 0, high = k;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canWin(candidates, mid, m, k)) {
                result[i] = min(result[i], mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    
    sort(result.begin(), result.end());
    
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}