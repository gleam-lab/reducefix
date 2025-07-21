#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M, K;
    cin >> N >> M >> K;

    vector<i64> A(N);
    for (i64 &a : A) {
        cin >> a;
    }

    vector<i64> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    vector<i64> prefix_sum(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }

    for (int i = 0; i < N; ++i) {
        i64 a = A[i];
        i64 low = 0, high = K, ans = -1;

        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 new_a = a + mid;

            // Find the number of candidates with votes > new_a
            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), new_a);
            int gt = sorted_A.end() - it;

            if (gt < M) {
                // Check if the remaining votes can be distributed such that at most M-1 candidates exceed new_a
                i64 remaining_votes = K - mid;

                // The candidates with votes > new_a will have at least new_a + 1 votes
                // The sum of their votes after distribution must be at least sum_{votes > new_a} (votes) + (M - gt) * (new_a + 1)
                // The remaining votes must be >= sum_{votes > new_a} (new_a + 1 - votes) + sum_{votes <= new_a} (max(0, new_a - votes))
                i64 sum_gt = prefix_sum[N] - prefix_sum[N - gt];
                i64 required = (new_a + 1) * (M - gt) - sum_gt;

                if (required <= remaining_votes) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                low = mid + 1;
            }
        }

        cout << ans << " ";
    }

    cout << endl;

    return 0;
}