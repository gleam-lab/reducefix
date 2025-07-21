#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, M, K;
    vector<long long> A(N);

    // Read input
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort candidates by votes (descending)
    vector<pair<long long, int>> votes(N);
    for (int i = 0; i < N; ++i) {
        votes[i] = {A[i], i};
    }
    sort(votes.rbegin(), votes.rend());

    // Calculate votes needed for each candidate
    vector<long long> additional_votes(N, -1); // -1 means cannot guarantee victory
    for (int i = 0; i < N; ++i) {
        if (i < M) {
            // Calculate votes needed to beat M-1 candidates ahead
            long long votes_needed = votes[i].first + K - (K - A[0]);
            // Check if possible with remaining votes
            if (votes_needed <= K) {
                additional_votes[0] = votes_needed - K;
            } else {
                additional_votes[0] = -1;
            }
        } else {
            // Check if can still guarantee victory with remaining votes
            if (A[i] + K - (K - A[0]) >= M) {
                additional_votes[votes[i].second] = 0;
            } else {
                additional_votes[votes[i].second] = -1;
            }
        }
    }

    // Output results
    for (int i = 0; i < N; ++i) {
        cout << additional_votes[i] << ' ';
    }
    cout << endl;

    return 0;
}