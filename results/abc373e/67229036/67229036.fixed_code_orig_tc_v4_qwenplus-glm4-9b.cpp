#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> votes(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> votes[i];
    }
    
    // Sort votes in descending order
    sort(votes.rbegin(), votes.rend());
    
    vector<long long> additional_votes(N);
    long long current_top_sum = 0;
    
    for (int i = 0; i < N; ++i) {
        // Calculate number of candidates with more votes than current
        long long more_voters = max(0, (long long)i - M + 1);
        
        // Calculate the sum of votes that would be in the top M
        long long top_M_sum = current_top_sum + votes[more_voters];
        
        // Calculate the votes needed to ensure victory
        long long votes_needed = top_M_sum - votes[i] + 1;
        
        // Update the additional_votes for this candidate
        additional_votes[i] = votes_needed;
        
        // Update the cumulative sum of votes
        current_top_sum += votes[i];
    }
    
    for (long long votes_needed : additional_votes) {
        cout << votes_needed << ' ';
    }
    
    return 0;
}