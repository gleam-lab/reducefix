#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool compare(const Candidate& a, const Candidate& b) {
    return a.votes > b.votes;
}

int main() {
    int N, M;
    long long K;
    cin >> N >> M >> K;
    
    vector<Candidate> candidates(N);
    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i + 1;
    }
    
    // Sort candidates by votes in descending order
    sort(candidates.begin(), candidates.end(), compare);
    
    // Calculate the total votes needed for the top M candidates
    long long totalVotesNeeded = 0;
    for (int i = 0; i < M; ++i) {
        totalVotesNeeded += candidates[i].votes;
    }
    
    // Calculate the remaining votes after giving votes to the top M candidates
    long long remainingVotes = K - totalVotesNeeded;
    
    // Initialize the result array
    vector<long long> result(N, -1);
    
    // Assign remaining votes to candidates
    int assigned = 0;
    for (int i = 0; i < N && remainingVotes > 0; ++i) {
        long long diff = candidates[i].votes - candidates[M].votes;
        if (diff > 0) {
            result[candidates[i].index - 1] = min(diff, remainingVotes);
            remainingVotes -= result[candidates[i].index - 1];
            assigned++;
        }
    }
    
    // Check if any candidate still needs votes
    for (int i = 0; i < N; ++i) {
        if (result[i] == -1) {
            result[i] = 0;
        }
    }
    
    // Print the results
    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}