#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

int main() {
    cin >> N >> M >> K;
    
    vector<ll> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    // Sort candidates by the number of votes they currently have
    vector<pair<ll, int>> candidates(N + 1);
    for (int i = 1; i <= N; ++i) {
        candidates[i] = {A[i], i};
    }
    sort(candidates.begin() + 1, candidates.begin() + N + 1);

    vector<ll> remaining_votes(N + 1, 0);
    ll total_votes = 0;
    for (int i = 1; i <= N; ++i) {
        remaining_votes[i] = K - total_votes;
        total_votes += A[candidates[i].second];
    }
    
    // Create a vector to store the minimum votes needed to guarantee victory
    vector<ll> votes_needed(N + 1, -1);

    // Iterate from the most popular to the least popular candidate
    for (int i = N, j = 1; i >= 1; --i, ++j) {
        ll votes_needed_to_win = (N - i) * candidates[i].first - candidates[i].first + 1;
        ll current_votes = A[candidates[i].second];
        if (remaining_votes[j] >= votes_needed_to_win) {
            votes_needed[candidates[i].second] = votes_needed_to_win - current_votes;
        }
    }

    // Output the result
    for (int i = 1; i <= N; ++i) {
        cout << votes_needed[i] << " ";
    }
    cout << endl;

    return 0;
}