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
    
    // Sort candidates by votes (ascending)
    sort(A.begin(), A.end());
    
    vector<long long> additionalVotes(N);
    long long remainingVotes = K;
    
    // Calculate additional votes needed for each candidate
    for (int i = 0; i < N; ++i) {
        long long votesNeeded = M - 1 - i;
        if (votesNeeded <= 0) {
            additionalVotes[i] = 0;
            continue;
        }
        
        long long votesLeft = remainingVotes - A[i];
        if (votesLeft < 0) {
            additionalVotes[i] = -1; // Not enough remaining votes to guarantee victory
            continue;
        }
        
        additionalVotes[i] = votesNeeded;
        remainingVotes -= votesLeft;
    }
    
    // Output the results
    for (int i = 0; i < N; ++i) {
        cout << additionalVotes[i] << " ";
    }
    cout << endl;
    
    return 0;
}