#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    ll total_votes = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_votes += A[i];
    }

    K -= total_votes;

    vector<pair<ll, int>> candidates(N);
    for (int i = 0; i < N; ++i) {
        candidates[i] = {A[i], i + 1};
    }

    // Sort candidates by votes received so far
    sort(candidates.begin(), candidates.end());

    vector<ll> votes_needed(N);
    for (int i = 0; i < N; ++i) {
        // Calculate votes needed to ensure candidate i is elected
        // They need to have more votes than M-1 candidates
        ll lower_bound_index = (M - 1 < N) ? M - 1 : N;
        ll votes_needed_to_be_trees = candidates[lower_bound_index].first + 1 - A[candidates[lower_bound_index].second - 1];
        
        if (i >= M - 1) {
            // If they are among the top M-1, calculate the exact votes needed
            votes_needed[i] = votes_needed_to_be_trees - A[candidates[i].second - 1];
        } else {
            // If they are not among the top M-1, they need votes to get into the top M-1
            votes_needed[i] = votes_needed_to_be_trees - A[candidates[i].second - 1];
        }
    }

    // Sort votes needed by the index of the candidate
    sort(votes_needed.begin(), votes_needed.end(), [&](ll a, ll b) {
        return candidates[a].second < candidates[b].second;
    });

    // Output the votes needed for each candidate
    for (int i = 0; i < N; ++i) {
        if (votes_needed[i] <= 0) {
            cout << 0 << ' ';
        } else if (votes_needed[i] > K) {
            cout << -1 << ' ';
        } else {
            cout << votes_needed[i] << ' ';
        }
    }

    return 0;
}