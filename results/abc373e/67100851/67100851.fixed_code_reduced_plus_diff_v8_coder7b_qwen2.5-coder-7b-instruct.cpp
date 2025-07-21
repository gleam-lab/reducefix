#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(const vector<Candidate>& candidates, int idx, long long additionalVotes, int M) {
    // Create a copy of the candidates vector and add the additional votes to the target candidate
    vector<Candidate> modifiedCandidates = candidates;
    modifiedCandidates[idx].votes += additionalVotes;
    
    // Sort the modified candidates by votes in descending order
    sort(modifiedCandidates.begin(), modifiedCandidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
    });
    
    // Check if the target candidate is ahead of the next M candidates
    for (int i = 1; i <= M; ++i) {
        if (modifiedCandidates[i].votes >= modifiedCandidates[idx].votes) {
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
    
    vector<long long> result(N, -1);
    
    // Binary search for the minimum additional votes needed for each candidate
    for (int i = 0; i < N; ++i) {
        long long left = 0, right = K - accumulate(candidates.begin(), candidates.end(), 0LL);
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canWin(candidates, i, mid, M)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        if (left <= K - accumulate(candidates.begin(), candidates.end(), 0LL)) {
            result[i] = left;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}