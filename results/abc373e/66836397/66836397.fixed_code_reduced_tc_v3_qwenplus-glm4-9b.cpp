#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

long long calculate_min_votes(long long votes_needed, long long votes, long long comp_votes) {
    // Calculate the votes needed for the competitor to have the same votes as the candidate
    long long votes_needed_to_equal = votes - comp_votes;
    
    // If the candidate already has more votes, no additional votes are needed
    if (votes_needed_to_equal <= 0) {
        return 0;
    }
    
    // If the competitor needs more votes than the candidate needs, they can't catch up
    if (votes_needed_to_equal > votes_needed) {
        return -1;
    }
    
    // Calculate votes needed for the candidate to have more than the competitor
    long long votes_needed_to_lead = votes_needed - votes_needed_to_equal + 1;
    
    // If the candidate already leads the competitor by votes_needed_to_lead, no additional votes are needed
    if (votes_needed_to_lead <= 0) {
        return 0;
    }
    
    return votes_needed_to_lead;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> A(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort the votes to easily find the M-th place
    sort(A.begin(), A.end());
    
    // This array will store the minimum additional votes needed for each candidate
    vector<long long> additional_votes(N, -1);
    
    // Calculate the votes needed for each candidate to guarantee their victory
    for (int i = 0; i < N; ++i) {
        if (i < N - M) {
            // If the candidate is among the top M, they need votes to stay ahead of the M-th candidate
            long long votes_needed = M * A[N - M - 1] - A[i];
            additional_votes[i] = calculate_min_votes(votes_needed, A[i], (N - M - 1) * A[N - M - 1]);
        } else {
            // If the candidate is not among the top M, they need votes to reach the M-th candidate
            long long votes_needed = A[N - M - 1] - A[i];
            additional_votes[i] = calculate_min_votes(votes_needed, A[i], (N - M - 1) * A[N - M - 1]);
        }
    }
    
    // Output the result
    for (int i = 0; i < N; ++i) {
        cout << additional_votes[i] << " ";
    }
    
    return 0;
}