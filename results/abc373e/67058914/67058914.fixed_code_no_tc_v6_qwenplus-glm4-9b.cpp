#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int N, M, K;
    vector<ll> A;
    
    cin >> N >> M >> K;
    A.resize(N);
    
    for (ll &a : A) {
        cin >> a;
    }
    
    // Create a vector of pairs (votes, index)
    vector<pair<ll, int>> votes(N);
    for (int i = 0; i < N; ++i) {
        votes[i] = {A[i], i};
    }
    
    // Sort by votes in descending order
    sort(votes.rbegin(), votes.rend());
    
    // Calculate the votes needed to guarantee at least M votes
    vector<ll> needed_votes(N);
    ll remaining_votes = K;
    for (int i = 0; i < N; ++i) {
        ll votes_needed = M - 1 - i; // M-1 because already have 1 vote
        if (votes_needed > 0) {
            needed_votes[i] = votes_needed;
        } else {
            needed_votes[i] = -1; // Cannot guarantee M votes
        }
        remaining_votes -= votes[i].first;
    }
    
    // Check if the current votes guarantee M votes
    int candidates_with_at_least_M_votes = 0;
    for (int i = 0; i < N && candidates_with_at_least_M_votes < M; ++i) {
        if (votes[i].first + remaining_votes >= M) {
            candidates_with_at_least_M_votes++;
        }
    }
    
    // Calculate the minimum votes to guarantee victory for each candidate
    vector<ll> min_votes_to_win(N);
    for (int i = 0; i < N; ++i) {
        if (candidates_with_at_least_M_votes >= M) {
            min_votes_to_win[i] = 0; // Already guaranteed victory
        } else {
            min_votes_to_win[i] = -1; // Cannot guarantee victory
        }
    }
    
    // Output the result
    for (ll votes : min_votes_to_win) {
        cout << votes << ' ';
    }
    cout << '\n';
    
    return 0;
}