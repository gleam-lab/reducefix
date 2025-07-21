#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

int main() {
    cin >> N >> M >> K;

    vector<pair<ll, int>> A(N + 1);
    vector<ll> current_votes(N + 1);
    
    ll sum_votes = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i].first;
        sum_votes += A[i].first;
        current_votes[i] = A[i].first;
        A[i].second = i;
    }

    // Sort candidates by the number of votes they received so far
    sort(A.begin() + 1, A.begin() + N + 1);
    
    vector<ll> additional_votes(N + 1);
    vector<int> already_victorious(N + 1, 0);

    for (int i = 1; i <= N - M; ++i) {
        additional_votes[A[i].second] = -1;
    }

    for (int i = N - M + 1; i <= N; ++i) {
        ll remaining_votes = K - sum_votes;

        ll votes_needed = M * (A[i].first + remaining_votes - K) - sum_votes;
        additional_votes[A[i].second] = votes_needed;

        // If current votes are enough to be victorious under any scenario
        if (A[i].first + remaining_votes - K >= M) {
            already_victorious[A[i].second] = 1;
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (already_victorious[i]) {
            additional_votes[i] = 0;
        } else if (additional_votes[i] < 0) {
            additional_votes[i] = -1;
        }

        cout << additional_votes[i] << " ";
    }

    return 0;
}