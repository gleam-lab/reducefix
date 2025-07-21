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

    // Sort candidates based on votes
    vector<pair<long long, int>> votes(N);
    for (int i = 0; i < N; ++i) {
        votes[i] = {A[i], i};
    }
    sort(votes.rbegin(), votes.rend()); // Sort in descending order

    // Calculate the minimum additional votes needed for each candidate
    vector<long long> min_votes(N);
    long long required_votes = votes[M-1].first; // Mth element is the threshold
    for (int i = 0; i < N; ++i) {
        if (votes[i].first < required_votes) {
            long long needed = max(0LL, required_votes - votes[i].first);
            min_votes[i] = needed;
        } else {
            min_votes[i] = 0;
        }
    }

    // Check if the remaining votes are enough
    long long sum_A = 0;
    for (int i = 0; i < N; ++i) {
        sum_A += A[i];
    }
    long long remaining_votes = K - sum_A;
    for (int i = 0; i < N; ++i) {
        if (min_votes[i] > remaining_votes) {
            min_votes[i] = -1;
        }
    }

    // Output the results
    for (int i = 0; i < N; ++i) {
        cout << min_votes[i] << " ";
    }
    cout << endl;

    return 0;
}