#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort candidates based on the number of votes received
    sort(A.begin(), A.end());
    
    // Calculate the cumulative sum of votes
    vector<long long> prefix(N);
    prefix[0] = A[0];
    for (int i = 1; i < N; ++i) {
        prefix[i] = prefix[i-1] + A[i];
    }
    
    // Calculate the remaining votes (total votes - sum of current votes)
    long long remaining_votes = K - prefix[N-1];
    
    // Result vector to store the minimum additional votes required for each candidate
    vector<long long> result(N);
    for (int i = 0; i < N; ++i) {
        long long votes_needed = 0;
        
        // Binary search to find the minimum votes needed to surpass M-1 candidates
        int low = 0, high = N - 1, mid, ans = N-1;
        while (low <= high) {
            mid = (low + high) / 2;
            long long current_votes = prefix[mid];
            
            if (current_votes - prefix[i] > M - 1) {
                ans = mid - 1;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        // Calculate the minimum additional votes required
        long long max_votes = prefix[ans] + remaining_votes;
        votes_needed = max_votes - (prefix[i] + A[i]);
        
        // Check if the candidate can guarantee their victory
        if (votes_needed <= remaining_votes) {
            result[i] = votes_needed;
        } else {
            result[i] = -1;
        }
    }
    
    // Output the result for each candidate
    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    
    return 0;
}