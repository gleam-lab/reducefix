#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Step 1: Sort candidates by votes received
    sort(A.begin(), A.end(), greater<long long>());

    // Step 2: Determine the votes needed to guarantee victory
    vector<long long> needed_votes(N);
    if (M == 1) {
        needed_votes = A; // All candidates need the same number of votes
    } else {
        needed_votes[M-1] = (long long)ceil((double)A[M-1] * (M + N - 2) / (N - 1));
        for (int i = M; i < N; i++) {
            needed_votes[i] = (long long)ceil((double)A[i] * M / (N - 1));
        }
    }

    // Step 3: Calculate additional votes needed
    long long remaining_votes = K - accumulate(A.begin(), A.end(), 0LL);
    for (int i = 0; i < N; i++) {
        long long votes_needed = needed_votes[i] - A[i];
        if (votes_needed > 0 && votes_needed <= remaining_votes) {
            needed_votes[i] = votes_needed;
        } else {
            needed_votes[i] = -1;
        }
    }

    // Step 4: Output results
    for (long long votes : needed_votes) {
        cout << votes << ' ';
    }
    cout << '\n';

    return 0;
}