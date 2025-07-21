#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<pair<ll, int>> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first;
    }

    // We will store the required additional votes in this array
    vector<ll> result(N);

    // For each candidate, determine how many extra votes they need
    for (int i = 0; i < N; ++i) {
        A[i].second = i;
    }

    // Sort the candidates by current votes
    sort(A.begin(), A.end());

    // Precompute prefix sums of current votes
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + A[i].first;
    }

    auto compute_required = [&](int idx) -> ll {
        ll cur = A[idx].first;
        ll remaining_votes = K;

        // Binary search for the minimum number of additional votes needed
        ll low = 0;
        ll high = remaining_votes + 1;
        while (low < high) {
            ll mid = (low + high) / 2;
            ll total = cur + mid;

            // How many other candidates have more than total?
            int cnt = N - (upper_bound(A.begin(), A.end(), make_pair(total, N)) - A.begin());

            if (cnt >= M) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        // After binary search, low is the minimum X to guarantee win
        return low;
    };

    // Compute required votes for each candidate
    vector<pair<ll, int>> results(N);
    for (int i = 0; i < N; ++i) {
        ll required = compute_required(i);
        results[i] = {required, A[i].second};
    }

    // Sort back to original order
    sort(results.begin(), results.end(), [](const pair<ll, int>& a, const pair<ll, int>& b) {
        return a.second < b.second;
    });

    // Output the result
    for (int i = 0; i < N; ++i) {
        cout << results[i].first << " ";
    }

    return 0;
}