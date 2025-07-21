#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> A(N), votes(N), min_votes(N, K); // min_votes to track minimum votes needed to guarantee victory

    // Read votes and compute prefix sum of votes
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        K -= A[i]; // Subtract counted votes from K
    }

    // Sort candidates by votes received to simplify the logic
    sort(A.begin(), A.end(), greater<long long>());

    // Calculate minimum votes needed for each candidate to guarantee victory
    for (int i = 0; i < N; i++) {
        // Number of votes difference to the M-th candidate (or the next candidate if there are less than M candidates)
        long long diff = max(0LL, A[i] - A[min(M, N) - 1]);

        // Calculate the maximum votes that can be distributed among the remaining candidates
        long long max_distributed_votes = min((long long)N - M, (long long)(K / (N - M)));

        // Calculate the minimum votes needed for the current candidate to be guaranteed
        min_votes[i] = max(diff - max_distributed_votes, 0LL);
    }

    // Output the minimum votes needed for each candidate
    for (int i = 0; i < N; i++) {
        if (min_votes[i] == K) {
            cout << -1 << " "; // If the candidate needs all remaining votes to guarantee victory, they can't
        } else {
            cout << min_votes[i] << " "; // Otherwise, print the minimum votes needed
        }
    }
    cout << endl;

    return 0;
}