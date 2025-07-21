#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }

    ll rem = K - total;
    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);

    // Sort the candidates' current votes
    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }

    vector<int> result(N);
    for (int i = 0; i < N; ++i) {
        ll a_i = A[i];

        // Binary search for minimum X
        ll low = 0, high = rem + 1;
        while (low < high) {
            ll mid = (low + high) / 2;
            ll new_score = a_i + mid;

            // Find how many scores are strictly greater than new_score
            int r = lower_bound(sorted_A.begin(), sorted_A.end(), new_score) - sorted_A.begin();
            int upper_cnt = N - r;

            if (upper_cnt < M) {
                // Not enough people above to prevent election
                high = mid;
            } else {
                // Need to increase score so more people fall below
                low = mid + 1;
            }
        }

        ll X = low;
        ll new_score = A[i] + X;

        // Now verify if with this X, candidate i can guarantee win
        // Find number of people who have score > new_score
        int r = lower_bound(sorted_A.begin(), sorted_A.end(), new_score) - sorted_A.begin();
        ll upper_cnt = N - r;

        if (upper_cnt < M) {
            result[i] = X;
        } else {
            result[i] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}