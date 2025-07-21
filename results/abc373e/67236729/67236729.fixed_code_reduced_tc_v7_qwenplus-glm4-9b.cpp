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

    // Sort the votes in descending order
    sort(A.rbegin(), A.rend());

    // Prepare to calculate the minimum additional votes needed
    vector<long long> min_votes_needed(N, 0);

    // The candidate at position M-1 needs to secure the M-th position
    if (M - 1 < N) {
        long long votes_needed = (long long)M - 1 - (A[M - 1] - A[M]);
        min_votes_needed[M - 1] = votes_needed;
    }

    // Calculate for the rest of the candidates
    for (int i = 0; i < M - 1; ++i) {
        long long votes_needed = K - A[i] + 1 - (N - M);
        min_votes_needed[i] = votes_needed > (A[M - 1] - A[i]) ? votes_needed : A[M - 1] - A[i];
    }

    // Output the results
    for (int i = 0; i < N; ++i) {
        cout << min_votes_needed[i] << " ";
    }
    cout << endl;

    return 0;
}