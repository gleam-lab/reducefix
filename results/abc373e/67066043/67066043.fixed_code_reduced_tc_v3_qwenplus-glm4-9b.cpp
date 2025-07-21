#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Pair each candidate's votes with their index and sort by votes
    vector<pair<long long, int>> votes(N);
    for (int i = 0; i < N; i++) {
        votes[i] = {A[i], i};
    }
    sort(votes.begin(), votes.end());

    // Calculate the votes needed for the top M candidates
    long long topMVotes = 0;
    for (int i = N - 1; i >= N - M; i--) {
        topMVotes = max(topMVotes, votes[i].first);
    }

    // Calculate the votes left after distributing votes to candidates according to their current votes
    long long votesDistributed = 0;
    for (int i = 0; i < N; i++) {
        votesDistributed += votes[i].first;
    }

    // Calculate the remaining votes and the minimum additional votes needed for each candidate
    vector<long long> additionalVotes(N);
    long long remainingVotes = K - votesDistributed;
    for (int i = N - 1; i >= 0; i--) {
        if (votes[i].first < topMVotes) {
            // If the candidate's votes are less than the top M candidate's votes, calculate additional votes needed
            long long votesNeeded = topMVotes - votes[i].first;
            if (remainingVotes < votesNeeded) {
                // If the remaining votes are not enough, this candidate cannot win
                additionalVotes[votes[i].second] = -1;
            } else {
                // Otherwise, assign the required votes and update the remaining votes
                additionalVotes[votes[i].second] = votesNeeded - remainingVotes;
                remainingVotes = votesNeeded;
            }
        } else {
            // If the candidate is already guaranteed to win, no additional votes are needed
            additionalVotes[votes[i].second] = 0;
        }
    }

    // Output the result
    for (int i = 0; i < N; i++) {
        cout << additionalVotes[i] << (i < N - 1 ? " " : "");
    }
    cout << endl;

    return 0;
}