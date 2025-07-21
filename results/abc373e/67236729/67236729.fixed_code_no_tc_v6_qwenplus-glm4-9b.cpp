#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the votes in descending order
    sort(A.begin(), A.end(), greater<long long>());

    vector<long long> additional_votes(N, -1);
    long long sum_votes = 0;
    for (int i = 0; i < N; ++i) {
        sum_votes += A[i];
    }

    if (N - M == 0) {
        // If there's exactly one candidate behind the leader or no candidates behind the leader
        for (int i = 0; i < N; ++i) {
            additional_votes[i] = 0;
        }
    } else {
        long long votes_needed = 0;
        for (int i = M - 1; i < N; ++i) {
            votes_needed = max(votes_needed, A[0] - A[i]);
        }
        votes_needed = votes_needed * M + K - sum_votes;

        if (votes_needed > K) {
            votes_needed = -1; // Cannot guarantee victory
        } else {
            for (int i = M - 1; i < N; ++i) {
                additional_votes[i] = (A[0] - A[i]) * M;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << additional_votes[i] << " ";
    }
    cout << endl;

    return 0;
}