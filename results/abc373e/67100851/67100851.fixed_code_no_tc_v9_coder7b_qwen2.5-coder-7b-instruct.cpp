#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(const vector<Candidate>& candidates, int m, long long totalVotesLeft, int candidateIndex) {
    int numCandidatesWithMoreVotes = 0;
    
    // Count how many candidates have more votes than the current candidate
    for (const auto& candidate : candidates) {
        if (candidate.votes > candidates[candidateIndex].votes) {
            ++numCandidatesWithMoreVotes;
        }
    }
    
    // Check if the current candidate can still win after getting the required votes
    if (numCandidatesWithMoreVotes < m) {
        return true;
    }
    
    // Calculate the maximum additional votes the current candidate can get
    long long maxAdditionalVotes = totalVotesLeft / (m + 1);
    
    // Recalculate the number of candidates with more votes after receiving the maximum additional votes
    for (const auto& candidate : candidates) {
        if (candidate.votes + maxAdditionalVotes > candidates[candidateIndex].votes) {
            ++numCandidatesWithMoreVotes;
        }
    }
    
    // Check if the current candidate can still win after receiving the maximum additional votes
    return numCandidatesWithMoreVotes < m;
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
    
    // Sort candidates based on their votes in ascending order
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes < b.votes;
    });
    
    // Calculate the prefix sum of votes
    vector<long long> prefixSum(n + 1);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + candidates[i].votes;
    }
    
    // Calculate the total votes left to be distributed
    k -= prefixSum[n];
    
    // Calculate the minimum additional votes needed for each candidate
    vector<int> minVotesNeeded(n, -1);
    for (int i = 0; i < n; ++i) {
        if (canWin(candidates, m, k, i)) {
            long long lo = 0, hi = k;
            while (hi - lo > 1) {
                long long mid = lo + (hi - lo) / 2;
                if (canWin(candidates, m, k - mid, i)) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            minVotesNeeded[i] = hi;
        }
    }
    
    // Output the results
    for (int vote : minVotesNeeded) {
        cout << vote << " ";
    }
    cout << endl;
    
    return 0;
}