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

    // Sort the votes with their original indices
    vector<pair<long long, int>> votes(N);
    for (int i = 0; i < N; ++i) {
        votes[i] = {A[i], i};
    }
    sort(votes.begin(), votes.end());

    // Calculate how many votes are left to distribute
    long long votes_left = K;
    for (int i = 0; i < N; ++i) {
        votes_left -= votes[i].first;
    }

    vector<long long> additional_votes_needed(N, -1);

    // Calculate additional votes needed for each candidate
    for (int i = 0; i < N; ++i) {
        if (i >= M - 1) {
            // This candidate is already guaranteed to be in the top M
            additional_votes_needed[votes[i].second] = 0;
        } else {
            // Calculate the number of votes needed to surpass the M-th best candidate
            long long needed = votes[M-1].first - votes[i].first;
            if (votes_left >= needed) {
                additional_votes_needed[votes[i].second] = needed;
                votes_left -= needed;
            } else {
                // Not enough votes left to guarantee the M-th best position
                additional_votes_needed[votes[i].second] = -1;
            }
        }
    }

    // Output the results
    for (int i = 0; i < N; ++i) {
        cout << additional_votes_needed[i] << " ";
    }
    cout << endl;

    return 0;
}