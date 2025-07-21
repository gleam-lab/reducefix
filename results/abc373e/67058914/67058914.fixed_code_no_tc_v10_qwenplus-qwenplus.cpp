#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }
    ll remaining = K - total;

    // Prepare list of candidates sorted by current votes
    vector<pair<ll, int>> sorted_candidates(N);
    for (int i = 0; i < N; ++i) {
        sorted_candidates[i] = {A[i], i};
    }
    sort(sorted_candidates.begin(), sorted_candidates.end());

    // Precompute prefix sums
    vector<ll> prefix(N + 1);
    for (int i = 1; i <= N; ++i) {
        prefix[i] = prefix[i - 1] + sorted_candidates[i - 1].first;
    }

    vector<ll> result(N, -1);

    for (int i = 0; i < N; ++i) {
        ll current_votes = A[i];
        // Binary search on the minimum additional votes needed
        ll low = 0, high = remaining;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_vote = current_votes + mid;

            // Find how many candidates have votes > new_vote
            // Using the sorted list
            int idx = upper_bound(sorted_candidates.begin(), sorted_candidates.end(),
                                  make_pair(new_vote, N)) - sorted_candidates.begin();

            // idx now represents number of candidates with votes <= new_vote
            // So total candidates with strictly more is N - idx

            if (N - idx >= M) {
                // Not enough, try higher
                low = mid + 1;
            } else {
                // Try to find a lower valid value
                answer = mid;
                high = mid - 1;
            }
        }

        result[i] = (answer == -1 || answer > remaining) ? -1 : answer;
    }

    // Output results in original order
    for (int i = 0; i < N; ++i) {
        cout << max(0LL, result[i]) << " ";
    }
    cout << endl;

    return 0;
}