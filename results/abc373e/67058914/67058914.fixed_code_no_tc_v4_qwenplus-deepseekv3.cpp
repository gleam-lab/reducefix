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
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> original_indices(N);
    iota(original_indices.begin(), original_indices.end(), 0);
    sort(original_indices.begin(), original_indices.end(), [&](int i, int j) {
        return A[i] < A[j];
    });

    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = A[original_indices[i]];
    }

    vector<ll> prefix_sum(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }

    ll remaining_votes = K - prefix_sum[N];

    vector<ll> result(N, -1);

    for (int idx = 0; idx < N; ++idx) {
        ll current_votes = sorted_A[idx];
        ll low = 0;
        ll high = remaining_votes;
        ll best_X = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total_i = current_votes + mid;

            int left = 0;
            int right = N;
            while (left < right) {
                int mid_pos = (left + right) / 2;
                if (sorted_A[mid_pos] <= total_i) {
                    left = mid_pos + 1;
                } else {
                    right = mid_pos;
                }
            }
            int count_above = N - left;

            if (count_above < M) {
                best_X = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (best_X != -1) {
            result[original_indices[idx]] = best_X;
        } else {
            result[original_indices[idx]] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << ' ';
    }
    cout << '\n';

    return 0;
}