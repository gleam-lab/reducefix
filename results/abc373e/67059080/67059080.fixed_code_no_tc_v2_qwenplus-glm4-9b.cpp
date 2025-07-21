#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll N, M, K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Pair each candidate's votes with their index
    vector<pair<ll, int>> votes(A.begin(), A.end());

    // Sort the candidates by the number of votes they have received
    sort(votes.begin(), votes.end());

    // Calculate the votes left to be counted after the current count
    ll remaining_votes = K - accumulate(A.begin(), A.end(), 0LL);

    // Prepare to output the minimum votes needed for each candidate
    vector<ll> min_votes_needed(N, -1);

    // We need to consider the candidates from the one with the highest votes to the one with the lowest
    for (int i = N - 1; i >= 0; --i) {
        // Calculate the number of votes needed to ensure candidate i is in the top M, after the remaining votes are counted
        ll votes_needed = M - (N - i - 1) + votes[i].first + 1;
        // If the votes_needed is greater than the remaining_votes, it's impossible for them to win
        if (votes_needed > remaining_votes) {
            min_votes_needed[i] = -1;
        } else {
            // Otherwise, the votes_needed is the minimum votes needed to guarantee victory
            min_votes_needed[i] = votes_needed;
            // Deduct the votes_needed from the remaining_votes
            remaining_votes -= votes_needed;
        }
    }

    // Output the result
    for (ll v : min_votes_needed) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}