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

    // Sort candidates by votes received
    sort(A.begin(), A.end());

    vector<long long> required_votes(N, 0);
    for (int i = 0; i < N && i < M; ++i) {
        // Calculate the votes needed for each candidate to be in the top M
        required_votes[i] = A[i] + (M - 1 - i) * A[i] - (i * A[i] / 2);
    }

    vector<long long> remaining_votes(N);
    for (int i = N - 1; i >= 0; --i) {
        // Calculate remaining votes for each candidate after all previous candidates have been considered
        remaining_votes[i] = K - (N - 1 - i) * A[i];
    }

    vector<long long> ans(N);
    for (int i = 0; i < N; ++i) {
        // Determine the minimum votes needed for the candidate to secure their place
        if (A[i] >= required_votes[i]) {
            ans[i] = 0; // Already in top M
        } else if (remaining_votes[i] < required_votes[i]) {
            ans[i] = -1; // Cannot secure the victory
        } else {
            ans[i] = required_votes[i] - A[i];
        }
    }

    // Output results
    for (long long i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}