#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort candidates by their current votes
    sort(A.begin(), A.end(), greater<ll>());

    vector<ll> additional_votes(N);
    for (int i = 0; i < N; ++i) {
        if (i >= M) {
            // Calculate additional votes needed to beat M least popular candidates
            int next_candidate_index = i + 1;
            if (next_candidate_index >= N) {
                additional_votes[i] = 0; // If M is larger than the number of candidates
            } else {
                additional_votes[i] = A[next_candidate_index] - A[i] + 1;
            }
        } else {
            additional_votes[i] = -1; // Already guaranteed to win
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << additional_votes[i] << " ";
    }
    cout << endl;

    return 0;
}