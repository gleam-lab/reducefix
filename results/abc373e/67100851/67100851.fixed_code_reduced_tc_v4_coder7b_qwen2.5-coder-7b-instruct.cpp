#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(vector<Candidate>& candidates, long long remainingVotes, int candidateIndex, int M, long long totalVotes) {
    int greaterThan = 0;
    for (int i = 0; i < candidates.size(); ++i) {
        if (candidates[i].votes > candidates[candidateIndex].votes) {
            greaterThan++;
        }
    }
    
    // Calculate the required votes for the candidate to win
    long long requiredVotes = candidates[candidateIndex].votes + 1;
    if (greaterThan >= M) {
        requiredVotes += M * (M - 1) / 2;
    } else {
        requiredVotes += greaterThan * (greaterThan - 1) / 2;
    }
    
    // Check if the remaining votes can cover the required votes
    return remainingVotes >= (requiredVotes - candidates[candidateIndex].votes);
}

vector<long long> minAdditionalVotes(int N, int M, long long K, vector<long long>& votes) {
    vector<Candidate> candidates;
    for (int i = 0; i < N; ++i) {
        candidates.push_back({votes[i], i});
    }
    
    sort(candidates.begin(), candidates.end());
    long long totalCurrentVotes = accumulate(votes.begin(), votes.end(), 0LL);
    long long remainingVotes = K - totalCurrentVotes;
    
    vector<long long> results(N, -1);
    for (int i = 0; i < N; ++i) {
        if (canWin(candidates, remainingVotes, i, M, K)) {
            results[candidates[i].index] = 0;
        } else if (remainingVotes > 0) {
            results[candidates[i].index] = 1;
        }
    }
    
    return results;
}

int main() {
    int N, M;
    long long K;
    cin >> N >> M >> K;
    
    vector<long long> votes(N);
    for (int i = 0; i < N; ++i) {
        cin >> votes[i];
    }
    
    vector<long long> results = minAdditionalVotes(N, M, K, votes);
    
    for (int i = 0; i < N; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;
    
    return 0;
}