#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(vector<Candidate>& candidates, int idx, long long additionalVotes, int M) {
    int remainingCandidates = candidates.size() - M;
    vector<pair<long long, int>> sortedCandidates = candidates;
    sort(sortedCandidates.begin(), sortedCandidates.end());
    
    long long totalVotesNeeded = 0;
    for (int i = 0; i <= idx; ++i) {
        totalVotesNeeded += sortedCandidates[i].votes + additionalVotes;
    }
    
    long long currentMax = 0;
    for (int i = idx + 1; i < sortedCandidates.size(); ++i) {
        currentMax = max(currentMax, sortedCandidates[i].votes);
    }
    
    return totalVotesNeeded > currentMax * remainingCandidates;
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
    
    vector<long long> result(N, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    
    for (int i = 0; i < N; ++i) {
        pq.push({candidates[i].votes, i});
    }
    
    while (!pq.empty()) {
        auto [votes, idx] = pq.top();
        pq.pop();
        
        if (canWin(candidates, idx, 0, M)) {
            result[idx] = 0;
            continue;
        }
        
        long long additionalVotes = 0;
        while (true) {
            if (canWin(candidates, idx, additionalVotes, M)) {
                result[idx] = additionalVotes;
                break;
            }
            ++additionalVotes;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}