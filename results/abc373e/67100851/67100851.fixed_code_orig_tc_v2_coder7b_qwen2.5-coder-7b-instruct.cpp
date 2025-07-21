#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(const vector<Candidate>& candidates, int targetIndex, long long additionalVotes) {
    int n = candidates.size();
    int needed = 0;
    
    for (int i = 0; i < n; ++i) {
        if (i == targetIndex) continue;
        
        if (candidates[targetIndex].votes + additionalVotes > candidates[i].votes) {
            needed++;
        }
    }
    
    return needed <= min(n - 1, candidates.size() - 1 - (candidates.size() - n + candidates[targetIndex].index));
}

int main() {
    long long N, M, K;
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
    
    vector<long long> results(N, 0);
    
    for (int i = 0; i < N; ++i) {
        if (candidates[i].votes >= K) {
            results[i] = 0;
        } else {
            long long additionalVotes = 0;
            
            while (!canWin(candidates, i, additionalVotes)) {
                additionalVotes++;
            }
            
            results[i] = additionalVotes;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << results[i] << " ";
    }
    
    return 0;
}