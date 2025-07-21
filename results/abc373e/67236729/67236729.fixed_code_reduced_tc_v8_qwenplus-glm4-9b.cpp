#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort candidates by votes (descending)
    sort(A.begin(), A.end(), greater<int>());

    // Calculate the minimum votes required for each candidate
    vector<int> additional_votes(N, 0); // Initialize with 0
    for (int i = 0; i < N; ++i) {
        if (i < M) {
            // They are in the top M, calculate to stay safe
            additional_votes[i] = max(0, M * A[i] - A[i - 1]);
        } else {
            // They are not in the top M, calculate to become the Mth candidate
            additional_votes[i] = M * A[i] - A[M - 1] - (i - M + 1) * A[i];
        }
    }

    // Output the results
    for (int i = 0; i < N; ++i) {
        if (additional_votes[i] < 0) {
            cout << -1 << " ";
        } else {
            cout << additional_votes[i] << " ";
        }
    }
    cout << endl;

    return 0;
}