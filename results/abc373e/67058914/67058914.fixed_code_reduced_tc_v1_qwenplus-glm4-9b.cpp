#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum += A[i];
    }

    vector<pair<ll, int>> candidates;
    for (int i = 0; i < N; ++i) {
        candidates.emplace_back(A[i], i + 1); // Store both votes and index
    }

    // Sort candidates by votes received
    sort(candidates.begin(), candidates.end());

    // Calculate remaining votes to distribute
    ll remaining_votes = K - sum;

    vector<ll> additional_votes_needed(N);
    for (int i = 0; i < N; ++i) {
        int rank = i;
        int rank_needed = 0;
        // Calculate the number of votes the candidate needs to guarantee victory
        while (rank_needed < M && rank + rank_needed < N) {
            rank_needed++;
            rank += rank_needed;
        }
        // If the candidate is already the M-th or higher ranked
        // then they can not win regardless of additional votes
        if (rank >= M || rank < 0) {
            additional_votes_needed[i] = -1;
        } else {
            // How many more votes do they need?
            int remaining_candidates = N - rank;
            // Calculate how many votes the M-th candidate would get
            // if all remaining votes were distributed evenly
            ll votes_needed_to_be_Mth = candidates[M - 1].first + (remaining_votes / remaining_candidates);
            // Calculate if they need to be higher to guarantee victory
            int additional_needed = 0;
            while (candidates[i].first < votes_needed_to_be_Mth) {
                additional_needed++;
                votes_needed_to_be_Mth++;
            }
            additional_votes_needed[i] = additional_needed - 1;
        }
    }

    // Output the results
    for (int i = 0; i < N; ++i) {
        cout << additional_votes_needed[i] << ' ';
    }
    cout << '\n';

    return 0;
}