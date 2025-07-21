#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum += A[i];
    }

    // Create a vector ofNode with candidate values and sort it
    vector<pair<ll, int>> nodes(N);
    for (int i = 0; i < N; ++i) {
        nodes[i] = {A[i], i + 1};
    }
    sort(nodes.begin(), nodes.end());

    // Calculate the number of votes needed to guarantee victory for each candidate
    vector<ll> votes_needed(N);
    for (int i = 0; i < N; ++i) {
        ll votes = nodes[i].first;
        ll rank = i + 1;
        if (rank < M) {
            votes_needed[i] = -1; // Not enough candidates to win
        } else {
            ll remaining_votes = K - sum;
            // Sum of top M-1 candidates plus current candidate must be greater than sum of remaining votes
            ll required_sum = votes + remaining_votes + 1 - (M - rank);
            votes_needed[i] = required_sum - (nodes[rank - 1].first + remaining_votes);
        }
    }

    // Output the results
    for (ll needed : votes_needed) {
        cout << needed << " ";
    }
    cout << endl;

    return 0;
}