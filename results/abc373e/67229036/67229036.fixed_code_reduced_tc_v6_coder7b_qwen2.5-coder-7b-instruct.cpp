#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, M, K;
vector<ll> A;

bool can_win(ll candidate_votes, ll additional_votes) {
    vector<ll> sorted_votes(A.begin(), A.end());
    sort(sorted_votes.begin(), sorted_votes.end());

    // Calculate the sum of votes for candidates that could potentially win
    ll sum_of_potential_winners = 0;
    for (int i = 0; i < min(M, (ll)sorted_votes.size()); ++i) {
        sum_of_potential_winners += sorted_votes[i] + additional_votes;
    }

    // Check if the current candidate can still win
    return sum_of_potential_winners > sorted_votes[M] + additional_votes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        K -= A[i];
    }

    vector<ll> results(N, -1); // Initialize results with -1 (impossible to win)

    for (int i = 0; i < N; ++i) {
        ll candidate_votes = A[i];

        // Binary search for the minimum number of additional votes needed
        ll left = 0, right = K + 1;
        while (left < right) {
            ll mid = (left + right) / 2;
            if (can_win(candidate_votes, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        if (left <= K) {
            results[i] = left;
        }
    }

    // Output the results
    for (int i = 0; i < N; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;

    return 0;
}