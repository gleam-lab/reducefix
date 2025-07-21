#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, long long> P;

int main() {
    int N, M, K;
    vector<long long> A(N);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Calculate prefix sums of A
    vector<long long> prefix_sum(N + 1);
    for (int i = 1; i <= N; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + A[i - 1];
    }

    // Sort candidates by votes received, descending
    vector<P> candidates(N);
    for (int i = 0; i < N; i++) {
        candidates[i] = {A[i], i};
    }
    sort(candidates.rbegin(), candidates.rend());

    // Calculate the minimum additional votes needed for each candidate
    vector<long long> additional_votes(N);
    long long remaining_votes = K - prefix_sum[N];

    for (int i = 0; i < N; i++) {
        int current_candidate_index = candidates[i].second;
        long long current_votes = A[current_candidate_index];

        if (i < M) {
            // If there are M or fewer candidates ahead of this candidate, calculate votes needed to guarantee victory
            long long votes_needed = prefix_sum[N] - prefix_sum[current_candidate_index] - (N - 1 - i) * (current_votes + 1);
            if (votes_needed <= remaining_votes) {
                additional_votes[current_candidate_index] = votes_needed;
                remaining_votes -= votes_needed;
            } else {
                additional_votes[current_candidate_index] = -1;
            }
        } else {
            // If there are more than M candidates ahead, this candidate cannot secure victory
            additional_votes[current_candidate_index] = -1;
        }
    }

    // Output the results
    for (int i = 0; i < N; i++) {
        cout << additional_votes[i] << (i < N - 1 ? " " : "\n");
    }

    return 0;
}