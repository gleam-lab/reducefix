#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> A(N);
    cin >> A;

    // Sort the candidates by votes in descending order
    sort(A.rbegin(), A.rend());

    vector<long long> additional_votes_needed(N, 0);
    long long additional_votes_sum = 0;

    // Calculate votes needed for each candidate
    for (int i = 0; i < N; ++i) {
        if (i < M) {
            additional_votes_needed[i] = A[i + 1] - A[i];
        } else {
            // Candidate is not in the top M, cannot win
            additional_votes_needed[i] = -1;
        }
        additional_votes_sum += additional_votes_needed[i];
    }

    // Check if the solution is feasible
    if (additional_votes_sum <= K) {
        // Distribute remaining votes
        long long remaining_votes = K - additional_votes_sum;
        long long votes_per_candidate = remaining_votes / (N - M);
        long long extra_votes = remaining_votes % (N - M);

        for (int i = 0; i < N; ++i) {
            if (i < M && additional_votes_needed[i] != -1) {
                additional_votes_needed[i] += votes_per_candidate + (i < extra_votes ? 1 : 0);
            }
        }
    } else {
        fill(additional_votes_needed.begin(), additional_votes_needed.end(), -1);
    }

    // Output the result
    for (int i = 0; i < N; ++i) {
        cout << additional_votes_needed[i] << " ";
    }
    cout << endl;

    return 0;
}