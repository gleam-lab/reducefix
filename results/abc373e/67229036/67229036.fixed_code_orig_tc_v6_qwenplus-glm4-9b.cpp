#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> A(N);
    long long sum_votes = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum_votes += A[i];
    }
    vector<long long> additional_votes(N, -1); // -1 means unable to guarantee victory

    for (int i = 0; i < N; ++i) {
        // Binary search for the minimum additional votes needed
        long long l = 0, r = K - sum_votes + 1; // r is the max additional votes needed
        while (l + 1 < r) {
            long long m = (l + r) / 2;
            long long current_votes = A[i] + m;
            long long ahead = 0;
            // Count how many candidates have more votes than the current candidate
            for (int j = 0; j < N; ++j) {
                if (A[j] + m > current_votes) {
                    ahead++;
                }
            }
            // Adjust binary search bounds
            if (ahead < M) {
                r = m;
            } else {
                l = m;
            }
        }

        // Check if the candidate can be elected with `r` additional votes
        if (r <= K - sum_votes) {
            long long ahead = 0;
            for (int j = 0; j < N; ++j) {
                if (A[j] + r > A[i] + r) {
                    ahead++;
                }
            }
            if (ahead < M) {
                additional_votes[i] = r;
            }
        }
    }

    // Output the result
    for (int i = 0; i < N; ++i) {
        cout << additional_votes[i] << " ";
    }
    cout << endl;

    return 0;
}