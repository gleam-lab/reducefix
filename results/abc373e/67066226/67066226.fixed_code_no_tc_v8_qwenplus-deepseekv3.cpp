#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> order(N);
    iota(all(order), 0);
    sort(all(order), [&](int i, int j) { return A[i] < A[j]; });

    vector<ll> sorted_A = A;
    sort(all(sorted_A));

    vector<ll> prefix_sum(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }

    vector<ll> ans(N, -1);

    for (int i = 0; i < N; ++i) {
        ll low = 0, high = K, best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = sorted_A[i] + mid;

            // Find the number of candidates with votes >= new_votes
            auto it = lower_bound(all(sorted_A), new_votes);
            int cnt_gte = sorted_A.end() - it;

            // If the candidate is not in the top M, we need to reduce the count
            if (cnt_gte >= M) {
                // Need to ensure that at most M-1 candidates have >= new_votes
                // So, we need to increase mid to push others down
                low = mid + 1;
                continue;
            }

            // Calculate the total votes needed to ensure that no more than M-1 candidates have >= new_votes
            int idx = lower_bound(all(sorted_A), new_votes + 1) - sorted_A.begin();
            int required = max(0, N - M - (N - idx));
            ll total_needed = 0;

            if (required > 0) {
                int start = idx - required;
                if (start < 0) {
                    low = mid + 1;
                    continue;
                }
                total_needed = (new_votes - 1) * required - (prefix_sum[idx] - prefix_sum[start]);
            }

            if (total_needed + mid <= K) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        ans[order[i]] = best;
    }

    for (int i = 0; i < N; ++i) {
        if (ans[i] == -1) {
            // Check if the candidate is already in the top M without any additional votes
            ll current_votes = A[i];
            auto it = upper_bound(all(sorted_A), current_votes);
            int cnt_gte = sorted_A.end() - it;
            if (cnt_gte < M) {
                ans[i] = 0;
            }
        }
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}