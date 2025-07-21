#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> A(N);
    cin >> A;

    // Sort candidates by votes (descending order)
    sort(A.rbegin(), A.rend());

    // Calculate minimum votes needed for a candidate to guarantee a win
    long long max_votes = A[M-1];
    long long required_votes = max_votes + (M - 1);

    vector<long long> additional_votes(N, 0);

    // Calculate additional votes needed for each candidate
    for (int i = 0; i < N; ++i) {
        if (i >= M) {
            // If the candidate is outside the top M candidates, they need to get all remaining votes
            additional_votes[i] = K - A[i];
        } else {
            // If the candidate is in the top M candidates, calculate how many votes are needed to ensure a win
            additional_votes[i] = required_votes - A[i];
        }
    }

    for (int i = 0; i < N; ++i) {
        // If the candidate already has the required votes, they need 0 additional votes
        if (A[i] >= required_votes) {
            additional_votes[i] = 0;
        }
        // If the candidate cannot get enough votes even with all remaining, they need -1 additional votes
        if (additional_votes[i] > K - (N - M)) {
            additional_votes[i] = -1;
        }
        cout << additional_votes[i] << " ";
    }
    cout << endl;

    return 0;
}