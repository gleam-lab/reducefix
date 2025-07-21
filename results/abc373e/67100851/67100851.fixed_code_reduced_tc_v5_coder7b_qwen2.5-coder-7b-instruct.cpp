#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(vector<Candidate>& candidates, int i, long long additionalVotes, long long totalRemainingVotes, int M) {
    vector<long long> scores(candidates.size());
    
    // Calculate current scores
    for (int j = 0; j < candidates.size(); ++j) {
        scores[j] = candidates[j].votes + (j == i ? additionalVotes : 0);
    }
    
    // Sort scores in descending order
    sort(scores.begin(), scores.end(), greater<long long>());
    
    // Count how many candidates have more votes than candidate i
    int count = 0;
    for (int j = 1; j < M; ++j) {
        if (scores[j] > scores[0]) {
            ++count;
        } else {
            break;
        }
    }
    
    // Check if candidate i can win
    return count < M;
}

int main() {
    int N, M;
    long long K;
    cin >> N >> M >> K;
    
    vector<Candidate> candidates(N);
    long long totalVotes = 0;
    
    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
        totalVotes += candidates[i].votes;
    }
    
    // Remaining votes after counting initial votes
    long long remainingVotes = K - totalVotes;
    
    vector<long long> results(N, -1);
    
    // Sort candidates based on their votes
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes < b.votes;
    });
    
    for (int i = 0; i < N; ++i) {
        if (candidates[i].votes >= (totalVotes / (N - M + 1))) {
            results[candidates[i].index] = 0;
            continue;
        }
        
        long long additionalVotes = 1;
        while (!canWin(candidates, i, additionalVotes, remainingVotes, M)) {
            ++additionalVotes;
        }
        
        results[candidates[i].index] = additionalVotes;
    }
    
    // Print results
    for (int i = 0; i < N; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;
    
    return 0;
}