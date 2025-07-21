#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Create a copy of A to sort and maintain indices
    vector<pair<ll, ll>> B(N);
    for (ll i = 0; i < N; ++i) {
        B[i] = {A[i], i + 1}; // Store 1-based index
    }

    // Sort candidates by votes received
    sort(B.begin(), B.end());

    // Calculate the votes needed to win after the current votes are counted
    vector<ll> votes_needed(N);
    for (ll i = 0; i < N; ++i) {
        if (i < M) {
            votes_needed[i] = M - 1 - i; // Number of votes to win over the top M-1 candidates
        } else {
            votes_needed[i] = -1; // Cannot win as there are already M candidates with more votes
        }
    }

    // Calculate the minimum additional votes for each candidate
    vector<ll> additional_votes(N);
    for (ll i = 0; i < N; ++i) {
        if (votes_needed[i] == -1) {
            additional_votes[i] = -1; // Cannot win regardless of additional votes
            continue;
        }

        ll current_votes = B[i].first;
        ll current_index = B[i].second;
        ll remaining_votes = K - current_votes;

        // Find how many candidates have more votes than us if we get remaining_votes
        ll j = i;
        while (j < N && B[j].first == current_votes) {
            j++;
        }
        ll competitors_with_equal_votes = j - i;

        ll additional_votes_needed = votes_needed[i] - competitors_with_equal_votes;
        if (remaining_votes >= additional_votes_needed) {
            additional_votes[i] = additional_votes_needed;
        } else {
            additional_votes[i] = -1; // Not enough remaining votes to guarantee victory
        }
    }

    // Output the results
    for (ll i = 0; i < N; ++i) {
        cout << additional_votes[i] << (i < N - 1 ? ' ' : '\n');
    }

    return 0;
}