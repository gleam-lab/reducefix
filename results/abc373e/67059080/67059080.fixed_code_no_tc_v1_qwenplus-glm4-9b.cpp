#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<ll> A(N + 1);
    ll total_votes = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        total_votes += A[i];
    }

    // Calculate the votes left to be cast
    ll votes_left = K - total_votes;

    // Create a vector of candidates with their current votes and index
    vector<pair<ll, int>> candidates(N + 1);
    for (int i = 1; i <= N; ++i) {
        candidates[i] = {A[i], i};
    }

    // Sort candidates by their votes (descending order)
    sort(candidates.begin() + 1, candidates.begin() + N + 1, greater<pair<ll, int>>());

    vector<ll> min_votes_needed(N + 1, -1);

    // Calculate the minimum votes needed for each candidate to guarantee a win
    for (int i = 1; i <= N; ++i) {
        ll current_votes = candidates[i].first;
        int rank = i; // Rank of the candidate, which is how many candidates have more votes

        // Calculate the number of votes needed to guarantee a win
        ll needed_votes = votes_left - (N - rank) * current_votes;

        // Check if it's possible for the candidate to guarantee a win
        if (needed_votes >= 0 && rank < M) {
            if (rank + (votes_left - needed_votes) >= M) {
                min_votes_needed[candidates[i].second] = needed_votes;
            }
        }
    }

    // Output the minimum votes needed for each candidate
    for (int i = 1; i <= N; ++i) {
        cout << min_votes_needed[i] << (i < N ? " " : "");
    }

    return 0;
}